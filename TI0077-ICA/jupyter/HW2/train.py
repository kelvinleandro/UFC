import numpy as np
import pandas as pd

from functools import partial
from collections import namedtuple
from sklearn.cross_decomposition import PLSRegression
from sklearn.linear_model import LinearRegression, Ridge
from sklearn.metrics import r2_score, root_mean_squared_error
from sklearn.model_selection import KFold

from loading import load_data
from preprocessing import preprocess
from regressors import least_squares, ridge_regressor

def determination_coefficient(y_true, y_pred):
    return 1 - np.sum((y_true - y_pred)**2) / np.sum((y_true - np.mean(y_true))**2)

def my_ols_train(x,y, **kwargs):
    b, rss = least_squares(x,y)
    print(f'my OLS Regression: RSS = {rss}')
    return b

def my_ridge_train(x,y,penalty,**kwargs):
    b, rss = ridge_regressor(x,y, penalty)
    print(f'my Ridge Regression: RSS = {rss}')
    return b

def np_ols_train(x,y, **kwargs):
    b, rss = np.linalg.lstsq(x,y)
    print(f'numpy OLS Regression: RSS = {rss}')
    return b

def evaluate_model(x, y, predict, **kwargs):
    y_true = np.array(y)
    y_pred = predict(x) 
    r2 = r2_score(y_true, y_pred)
    rmse = root_mean_squared_error(y_true,y_pred)
    print('Test R^2:', r2)
    print('Test RMSE:', rmse)
    return r2, rmse

def customKFold(X, y, n_folds: int, seed:int=42):
    rng = np.random.RandomState(seed)
    n_samples = len(y)
    indices = np.arange(n_samples)
    rng.shuffle(indices)
    fold_sizes = (n_samples // n_folds) * np.ones(n_folds, dtype=int)
    fold_sizes[:n_samples % n_folds] += 1

    current = 0
    folds = []
    for fold_size in fold_sizes:
        start, stop = current, current + fold_size
        folds.append(indices[start:stop])
        current = stop

    for i in range(n_folds):
        val_indices = folds[i]
        train_indices = np.concatenate([folds[j] for j in range(n_folds) if j != i])

        X_train, X_val = X[train_indices], X[val_indices]
        y_train, y_val = y[train_indices], y[val_indices]
        yield (X_train, y_train), (X_val, y_val)





def kfold_training(X, y, train_and_predict, kfold_method='custom', n_folds=5, seed=42):
    """
    Perform cross-validation on a dataset for regression tasks from scratch.

    Parameters:
        X: The dataset.
        y: The labels.
        n_folds (int): Number of folds for cross-validation.

    Returns:
        float: Mean cross-validated RMSE.
    """
    rmse_scores = []
    rsqrd_scores = []
    best: tuple[np.ndarray, float] = (np.empty(1), float('inf'))

    if kfold_method == 'custom':
        for (X_train, y_train), (X_val, y_val) in customKFold(X, y, n_folds, seed):
            y_pred, b = train_and_predict(X_train, y_train, X_val)

            rmse = np.sqrt(np.mean((y_val - y_pred)**2))
            rsqrd = determination_coefficient(y_val, y_pred)

            if rmse < best[1]:
                best = (b, rmse)

            rmse_scores.append(rmse)
            rsqrd_scores.append(rsqrd)

    elif kfold_method == 'sklearn':
        kf = KFold(n_splits=n_folds, random_state=seed, shuffle=True)
        for train_index, val_index in kf.split(X):
            X_train, X_val = X[train_index], X[val_index]
            y_train, y_val = y[train_index], y[val_index]

            y_pred, b = train_and_predict(X_train, y_train, X_val)

            rmse = root_mean_squared_error(y_val, y_pred)
            rsqrd = r2_score(y_val, y_pred)

            if rmse < best[1]:
                best = (b, rmse)

            rmse_scores.append(rmse)
            rsqrd_scores.append(rsqrd)


    results = pd.DataFrame({
        'RMSE': rmse_scores,
        'R^2': rsqrd_scores,
        'Number of Folds': np.ones(n_folds)*n_folds
    })

    # results.loc['Mean'] = [np.mean(rmse_scores),np.mean(rsqrd_scores), n_folds]

    return results, best[0]

if __name__ == '__main__':
    (solTrainX, solTrainXtrans, solTrainY), \
    (solTestX, solTestXtrans, solTestY) = load_data()
    #
    # def fit_transform_ols(X_train, y_train, X_val):
    #     b,_ = least_squares(X_train, y_train)
    #     return X_val @ b, b
    #
    # def fit_transform_ridge(X_train, y_train, X_val, penalty):
    #     b,_ = ridge_regressor(X_train, y_train, penalty)
    #     return X_val @ b, b
    #
    # def fit_transform_pls(X_train, y_train, X_val, n_components):
    #     pls = PLSRegression(n_components)
    #     pls.fit(X_train, y_train)
    #     return pls.predict(X_val), pls.coef_
    #
    # def predict_pls(X, coefs):
    #     return X @ coefs.T
    #
    # def predict_ols(X, coefs):
    #     return X @ coefs
    #
    # predict_ridge = predict_ols
    #
    # print('OLS:')
    # for n_folds in [5,10]:
    #     print(f'OLS {n_folds} folds')
    #     results, b = kfold_training(
    #         preprocess(solTrainX),
    #         np.array(solTrainY),
    #         fit_transform_ols,
    #         n_folds=n_folds
    #     )
    #     # print(results)
    #     evaluate_model(solTestX, solTestY, partial(predict_ols, coefs=b))
    #
    # print('Ridge:')
    # for p in [1, 10, 100, 1_000, 10_000]:
    #     for n_folds in [5,10]:
    #         print(f'Ridge with {n_folds} folds and penalty {p=}')
    #         results, params = kfold_training(
    #             preprocess(solTrainX),
    #             np.array(solTrainY),
    #             partial(fit_transform_ridge, penalty=p),
    #             n_folds=n_folds)
    #         # print(results)
    #
    #         evaluate_model(solTestX, solTestY, partial(predict_ridge, coefs=params))
    #
    # pls_order = 2
    # print(f'PLS({pls_order}):')
    # for n_folds in [5,10]:
    #     print(f'PLS({pls_order}) with {n_folds} folds')
    #     results, params = kfold_training(preprocess(solTrainX),
    #                                 np.array(solTrainY),
    #                                 partial(fit_transform_pls, n_components=pls_order),
    #                                 n_folds=n_folds)
    #
    #     # print(results)
    #     evaluate_model(solTestX, solTestY, partial(predict_pls, coefs=params))
    # from sklearn.linear_model import Ridge
    #
    # def predict_ridge(X, coefs):
    #     return coefs.predict(X)
    #
    # def fit_transform_ridge(X_train, y_train, X_val, penalty):
    #     r = Ridge(alpha=penalty, fit_intercept=True, copy_X=True)
    #     r.fit(X_train, y_train)
    #     return r.predict(X_val), r
    #
    #
    # print('Ridge')
    # ridge_result_sklearn = pd.DataFrame()
    # START = 0.1
    # END = 20
    # penalties = np.exp(np.linspace(np.log(START), np.log(END), 20))
    # # for p in penalties:
    # solTrainX_preprocessed = preprocess(solTrainX)
    # solTestX_preprocessed = preprocess(solTestX)
    # for p in [0, 1]:
    #     for n_folds in [5,10]:
    #         print(f'Ridge with {n_folds} folds and penalty {p=}')
    #         result, params = kfold_training(
    #             solTrainX_preprocessed,
    #             np.array(solTrainY),
    #             partial(fit_transform_ridge, penalty=p),
    #             n_folds=n_folds, kfold_method='sklearn')
    #
    #         result['lambda'] = p
    #         ridge_result_sklearn = pd.concat([ridge_result_sklearn, result])
    #
    #         evaluate_model(solTestX_preprocessed, solTestY, partial(predict_ridge, coefs=params), add_intercept=True)
    def fit_transform_ols(X_train, y_train, X_val):
        b,_ = least_squares(X_train, y_train)
        return X_val @ b, b

    def predict_ols(X, coefs):
        return X @ coefs

    print('OLS custom:')
    ols_result_custom = pd.DataFrame()
    ols_scaler_path = './scalers/ols_scaler.gz'
    ols_scaler_path = None
    solTrainX_preprocessed = preprocess(solTrainX, save_path=ols_scaler_path, add_intercept=True)
    solTestX_preprocessed = preprocess(solTestX, load_path=ols_scaler_path, add_intercept=True)
    for n_folds in [5,10]:
        print(f'OLS {n_folds} folds')
        result, b = kfold_training(
            solTrainX_preprocessed,
            np.array(solTrainY),
            fit_transform_ols,
            n_folds=n_folds
        )

        ols_result_custom = pd.concat([ols_result_custom, result])
        evaluate_model(solTestX_preprocessed, solTestY, partial(predict_ols, coefs=b))

import numpy as np

def least_squares(x,y) -> tuple[np.ndarray, float]:
    """
    Return:
        b: Coefficients of the linear regression
        residuals: Sum of squared residuals
    """
    b = np.linalg.pinv(x) @ y
    return b, np.sum((x @ b - y)**2)

def ridge_regressor(x,y,penalty) -> tuple[np.ndarray, float]:
    b = np.linalg.inv(x.T @ x + penalty * np.eye(x.shape[1])) @ x.T @ y
    return b, np.sum((x @ b - y)**2)

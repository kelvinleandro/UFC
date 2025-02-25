from sklearn import preprocessing
from os import path
import numpy.typing as npt
import numpy as np
import joblib

def preprocess(data, 
               load_path: str | None = None,
               save_path: str | None = None,
               add_intercept: bool = False):

    # Removing data with NAN                
    data = data.dropna()

    # ndarray
    data = np.array(data)

    # Remove skewness
    data = skewness_remove(data)

    if load_path is not None:
        ss = joblib.load(load_path)
    else:
        ss = preprocessing.StandardScaler()
        ss.fit(data)
        ss.transform(data)

    # Scaling the data
    data = ss.transform(data)

    if save_path is not None:
        joblib.dump(ss, save_path)

    # Adding intercept term
    if add_intercept:
        data = np.append(data, np.ones((np.shape(data)[0], 1)), axis=1)

    return data

def skewness_remove(data):
    return np.log(data + 1)



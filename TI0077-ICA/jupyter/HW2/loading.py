import pandas as pd

import os
from os import path
import zipfile

# Every path is relative to dirname
dirname = os.path.dirname(__file__)

def unzip_data():
    zip_path = path.join(dirname, 'data/solubility.zip')
    unzip_path = path.join(dirname, 'data/')
    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        zip_ref.extractall(unzip_path)

def load_data():
    """

    Return:
        (solTrainX, solTrainXtrans, solTrainY), (solTestX, solTestXtrans, solTestY) 
    """
    def read(fpath):
        return pd.read_csv(path.join(dirname, fpath), sep='\\s+')

    solTestX = read('../data/solubility/solTestX.txt')
    solTestXtrans = read('../data/solubility/solTestXtrans.txt')
    solTestY = read('../data/solubility/solTestY.txt')
    solTrainX = read('../data/solubility/solTrainX.txt')
    solTrainXtrans = read('../data/solubility/solTrainXtrans.txt')
    solTrainY = read('../data/solubility/solTrainY.txt')
    return (solTrainX, solTrainXtrans, solTrainY), (solTestX, solTestXtrans, solTestY) 
    
if __name__ == '__main__':
    (solTrainX, solTrainXtrans, solTrainY), (solTestX, solTestXtrans, solTestY)  = load_data()

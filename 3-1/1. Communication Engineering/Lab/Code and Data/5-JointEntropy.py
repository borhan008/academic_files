import pandas as pd
import numpy as np

data = pd.read_csv("data/^TWII.csv")
data['Date'] = pd.to_datetime(data['Date'], format='%Y-%m-%d')
data.sort_values(by='Date', ascending=True, inplace=True)

#X
X = data['Adj Close']
X= np.log(data['Adj Close']) - np.log(data['Adj Close'].shift(1))
X = X.dropna()

# Y
Y = data['Open']
Y = np.log(data['Open']) - np.log(data['Open'].shift(1))
Y = Y.dropna()

def jointEntropy(X, Y, bins) :
    binned_XY = np.histogram2d(X, Y, bins)[0]
    probsXY = binned_XY / np.sum(binned_XY)
    probsXY = probsXY[np.nonzero(probsXY)]
    jointEntropy = -np.sum(probsXY * np.log2(probsXY));
    return jointEntropy

print(jointEntropy(X, Y, 12))


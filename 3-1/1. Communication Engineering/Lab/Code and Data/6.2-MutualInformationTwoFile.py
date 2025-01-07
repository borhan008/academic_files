import pandas as pd
import numpy as np

# X
data = pd.read_csv("data/^SSMI_swizerland.csv")
X = data[['Date', 'Close']];
X.loc[:, 'Date'] = pd.to_datetime(X['Date'])
X['Close'] = np.log(X['Close']) - np.log(X['Close'].shift(1));
X = X[X['Close'].notna()];
X.sort_values(by='Date', ascending=True, inplace=True)
X.dropna()

# Y
data2 = pd.read_csv("data/^TWII.csv");
Y = data2[['Date', 'Close']];
Y.loc[:, 'Date'] = pd.to_datetime(Y['Date'])
Y['Close'] = np.log(Y['Close']) - np.log(Y['Close'].shift(1))   
Y = Y[Y['Close'].notna()];
Y.sort_values(by='Date', ascending=True, inplace=True)
Y.dropna()


# Merge
XY = pd.merge(X, Y, on='Date', how='inner');

print(XY.head());

def entropy(X, bins):
    binned_dist = np.histogram(X, bins)[0]
    probs = binned_dist / np.sum(binned_dist)
    probs = probs[np.nonzero(probs)]
    entropy = -np.sum(probs * np.log2(probs))
    return entropy

def jointEntropy(X, Y, bins) :
    binned_XY = np.histogram2d(X, Y, bins)[0]
    probsXY = binned_XY / np.sum(binned_XY)
    probsXY = probsXY[np.nonzero(probsXY)]
    jointEntropy = -np.sum(probsXY * np.log2(probsXY));
    return jointEntropy

def mutualInformation(X, Y, bins) :
    return entropy(X, bins) + entropy(Y, bins) - jointEntropy(X, Y, bins)

print(mutualInformation(XY['Close_x'], XY['Close_y'], 12));


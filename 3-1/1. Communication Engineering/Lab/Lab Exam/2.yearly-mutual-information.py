import pandas as pd
import numpy as np

# X
data = pd.read_csv("newData/daewooship_marin_eng.csv");
X = data[['Date', 'Close']]
X = X.copy()
X.loc[:, 'Date'] = pd.to_datetime(X['Date'])
X.loc[:, 'Close'] = np.log(X['Close']) - np.log(X['Close'].shift(1));
X = X[X['Close'].notna()];
X.sort_values(by='Date', ascending=True, inplace=True)
X = X.dropna()

# Y
Y = data[['Date', 'Open']];
Y = Y.copy()

Y.loc[:, 'Date'] = pd.to_datetime(Y['Date'])
Y['Open'] = pd.to_numeric(Y['Open'], errors='coerce')

Y.loc[:, 'Open']  = np.log(Y['Open']) - np.log(Y['Open'].shift(1))   
Y = Y[Y['Open'].notna()];
Y.sort_values(by='Date', ascending=True, inplace=True)
Y = Y.dropna()

# Merge
XY = pd.merge(X, Y, on='Date', how='inner');


def entropy(X, bins):
    binned_dist, bin_edges = np.histogram(X, bins)
    probs = binned_dist / np.sum(binned_dist)
    probs = probs[np.nonzero(probs)]
    entropy = -np.sum(probs * np.log2(probs))
   
    return entropy

def jointEntropy(X, Y, bins):
    binned_XY, binnedX, binnedY = np.histogram2d(X, Y, bins)
    probsXY = binned_XY / np.sum(binned_XY)
    probsXY = probsXY[np.nonzero(probsXY)]
    jointEntropy = -np.sum(probsXY * np.log2(probsXY))

    return jointEntropy

def mutualInformation(X, Y, bins) :
    entropyX = entropy(X, bins);
    entropyY = entropy(Y, bins);
    joint = jointEntropy(X, Y, bins);
    return entropyX + entropyY - joint


XY['Date'] = pd.to_datetime(XY['Date'])

unique_years = XY['Date'].dt.year.unique()
unique_years = sorted(unique_years)

for year in unique_years:
    yearly_data = XY[XY['Date'].dt.year == year]
    print(f"\n {year} Mutual Information: {mutualInformation(yearly_data['Close'], yearly_data['Open'], 12) : .4f}");


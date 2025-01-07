import pandas as pd
import numpy as np

data = pd.read_csv("data/^TWII.csv")
data['Date'] = pd.to_datetime(data['Date'], format='%Y-%m-%d')
data.sort_values(by='Date', ascending=True, inplace=True)

column = data['Adj Close']
column= np.log(data['Adj Close']) - np.log(data['Adj Close'].shift(1))
column = column.dropna()

def entropy(column, bins) :
    binned_dist = np.histogram(column, bins)[0]
    probs = binned_dist / np.sum(binned_dist)
    probs = probs[np.nonzero(probs)]
    print(probs)
    entropy = 0
    for i in range(len(probs)):
        entropy -= probs[i] * np.log2(probs[i]);
    return entropy

print(entropy(column, 12))
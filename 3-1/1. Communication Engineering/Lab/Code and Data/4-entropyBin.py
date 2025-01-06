import pandas as pd
import numpy as np

data = pd.read_csv("data/^TWII.csv")
column = data['Open']
column = column.dropna()


def entropy(column, bins) :
    binned_dist = np.histogram(column, bins)[0]
    probs = binned_dist / np.sum(binned_dist)
    probs = probs[np.nonzero(probs)]
    entropy = 0
    for i in range(len(probs)):
        entropy -= probs[i] * np.log2(probs[i]);
    return entropy

print(entropy(column, 100))
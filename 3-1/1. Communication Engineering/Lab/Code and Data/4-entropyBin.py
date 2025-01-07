import pandas as pd
import numpy as np

data = pd.read_csv("data/canada.csv")
data.loc[:, 'Date'] = pd.to_datetime(data['Date'])
data.sort_values(by='Date', ascending=True, inplace=True)

column = data['Close']
column= np.log(data['Close']) - np.log(data['Close'].shift(1))
column = column.dropna()

print(f"Max Value : {column.max()}")
print(f"Min Value : {column.min()}")
print(f"Differece : {column.max() - column.min()}")
print("Bins : 12")

def entropy(column, bins) :
    binned_dist, bin_edges = np.histogram(column, bins)
    probs = binned_dist / np.sum(binned_dist)
    bin_table = pd.DataFrame({
        'Bin Range': [f"[{bin_edges[i]:.4f}, {bin_edges[i+1]:.4f})" for i in range(len(bin_edges)-1)],
        'Frequency': binned_dist,
        'Probability': probs
    });
    print(bin_table)
    entropy = 0
    for i in range(len(probs)):
        entropy -= probs[i] * np.log2(probs[i]);
    return entropy

print(f"Entropy : {entropy(column, 12) : .4f}")
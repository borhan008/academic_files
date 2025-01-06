import pandas as pd
import numpy as np  

data = pd.read_csv("data/^TWII.csv")
column = data['Open']

values, counts = np.unique(column, return_counts=True)
counts = counts[np.nonzero(counts)]

prob = []

for i in range(len(counts)):  
    prob.append(counts[i] / len(column));

def entropy(prob) :
    entropy = 0
    for i in range(len(prob)):
        entropy -= prob[i] * np.log2(prob[i]);
    return entropy

print(entropy(prob))
    
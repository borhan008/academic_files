import pandas as pd
import numpy as np

data = pd.read_csv("data/^TWII.csv")

#OPEN
X = data['Open']
X = X.dropna()

# Close
Y = data['Close']
Y = Y.dropna()

def jointEntropy(X, Y, bins) :
    binned_XY = np.histogram2d(X, Y, bins)[0]
    probsXY = binned_XY / np.sum(binned_XY)
    probsXY = probsXY[np.nonzero(probsXY)]
    jointEntropy = -np.sum(probsXY * np.log2(probsXY));
    return jointEntropy

print(jointEntropy(X, Y, 100))


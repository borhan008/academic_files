import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns


data = pd.read_csv("data/^TWII.csv")

#X
X = data['Open']
X = X.dropna()

#Y
Y = data['Close']
Y = Y.dropna()

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
print(mutualInformation(X, Y, 100))

#Entropy of X
plt.title("Binned Distribution of X");
plt.hist(X, bins=100);
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.show();

#Joint Distribution of X and Y
joint_dist, x_edges, y_edges = np.histogram2d(X, Y, bins=100);
sns.heatmap(joint_dist);
plt.title("Joint Distribution of X and Y")
plt.xlabel("Bins of X (Open)")
plt.ylabel("Bins of Y (Close)")
plt.show();

#Mutual Information vs. Number of Bins
bin_ranges = range(10, 201, 10)  # Test for various bin sizes
mutual_info_values = [mutualInformation(X, Y, b) for b in bin_ranges]
plt.figure(figsize=(10, 6))
plt.plot(bin_ranges, mutual_info_values, marker='o', color="purple")
plt.title("Mutual Information vs. Number of Bins")
plt.xlabel("Number of Bins")
plt.ylabel("Mutual Information")
plt.grid()
plt.show()
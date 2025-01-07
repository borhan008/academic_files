import pandas as pd
import numpy as np

# X
data = pd.read_csv("data/canada.csv");
X = data[['Date', 'Close']];
X.loc[:, 'Date'] = pd.to_datetime(X['Date'])
X.loc[:, 'Close'] = np.log(X['Close']) - np.log(X['Close'].shift(1));
X = X[X['Close'].notna()];
X.sort_values(by='Date', ascending=True, inplace=True)
X = X.dropna()

# Y
data2 = pd.read_csv("data/^TWII.csv");
Y = data2[['Date', 'Close']];
Y.loc[:, 'Date'] = pd.to_datetime(Y['Date'])
Y.loc[:, 'Close']  = np.log(Y['Close']) - np.log(Y['Close'].shift(1))   
Y = Y[Y['Close'].notna()];
Y.sort_values(by='Date', ascending=True, inplace=True)
Y = Y.dropna()

# Merge
XY = pd.merge(X, Y, on='Date', how='inner');



def entropy(X, bins):
    print(f"Max Value : {X.max() : .4f}")
    print(f"Min Value : {X.min() : .4f}")
    print(f"Differece : {X.max() - X.min() : .4f}")
    print(f"Bins : {bins}")
    binned_dist, bin_edges = np.histogram(X, bins)
    probs = binned_dist / np.sum(binned_dist)
    

    bin_table = pd.DataFrame({
        'Bin Range': [f"[{bin_edges[i]:.4f}, {bin_edges[i+1]:.4f})" for i in range(len(bin_edges)-1)],
        'Frequency': binned_dist,
        'Probability': probs
    });
    print(bin_table)
    probs = probs[np.nonzero(probs)]
    entropy = -np.sum(probs * np.log2(probs))
   
    return entropy

def jointEntropy(X, Y, bins):
    binned_XY, binnedX, binnedY = np.histogram2d(X, Y, bins)
    probsXY = binned_XY / np.sum(binned_XY)

    # Show the joint distribution
    rows = []
    for i in range(len(binnedX) - 1):
        for j in range(len(binnedY) - 1):
            rows.append({
                'X Bin': f"[{binnedX[i]:.4f}, {binnedX[i+1]:.4f})",
                'Y Bin': f"[{binnedY[j]:.4f}, {binnedY[j+1]:.4f})",
                'Frequency': binned_XY[i, j],
                'Probability': probsXY[i, j]
            })

    table = pd.DataFrame(rows)
    print(table)   

    probsXY = probsXY[np.nonzero(probsXY)]
    jointEntropy = -np.sum(probsXY * np.log2(probsXY))

    return jointEntropy

def mutualInformation(X, Y, bins) :
    print("X : ");
    entropyX = entropy(X, bins);
    print(f"Entropy X, H(X) : {entropyX:.4f}");
    print("\n\nY : ");
    entropyY = entropy(Y, bins);
    print(f"Entropy Y, H(Y) : {entropyY:.4f}");
    print("\nJoint : ");
    joint = jointEntropy(X, Y, bins);
    print(f"Joint Entropy H(X, Y) : {joint:.4f}");
    return entropyX + entropyY - joint

print(f"\n Mutual Information: {mutualInformation(XY['Close_x'], XY['Close_y'], 12) : .4f}");


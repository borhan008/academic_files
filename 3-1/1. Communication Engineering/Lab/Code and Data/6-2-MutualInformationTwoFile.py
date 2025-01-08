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


def jointEntropy(X, Y, bins):
    binned_XY, binnedX, binnedY = np.histogram2d(X, Y, bins)
    probsXY = binned_XY / np.sum(binned_XY)

    binnedX = np.histogram(X, bins)[0]
    probsX = binnedX / np.sum(binnedX)
    probsX = probsX[np.nonzero(probsX)]

    
    binnedY = np.histogram(Y, bins)[0]
    probsY = binnedY / np.sum(binnedY)
    probsY = probsY[np.nonzero(probsY)]


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
    ans = 0;
    for i in range(len(probsXY)):
        ans += probsXY[i] * np.log2(probsXY[i] / (probsX[i % len(probsX)] * probsY[i // len(probsX)]))

    return ans


print(f"\n Mutual Information: {jointEntropy(XY['Close_x'], XY['Close_y'], 12) : .4f}");


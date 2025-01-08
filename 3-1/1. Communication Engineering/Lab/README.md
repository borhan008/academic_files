# Lab : Communication Engineering by Python

## Theoretical Concepts

---

**Entropy:**

$H(X) = - \sum P(x_i)\log_2P(x_i)$

**Joint Entropy:**

$H(X, Y) = - \sum_{x \epsilon X} \sum_{y \epsilon Y} P(x,y)\log_2P(x,y)$

**Mutual Information**

$M(X,Y) = H(X) + H(Y) - H(X,Y)$

## Packages

---

- Pandas
- NumPy
- SciPy

```bash
pip install pandas numpy scipy
```

## My File Structure

---

![image.png](https://i.ibb.co.com/q1W1K0n/image.png)

![image.png](https://i.ibb.co.com/nkxpFpK/image2.png)

## Code

---

**Reading a CSV file**

```python
import pandas as pd

data = pd.read_csv("data/^TWII.csv"); #reading .csv file
data2 = pd.read_excel("data/Chaina_shanghai.xlsx"); #reading .xlsx file
print(data.head());
print(data2.head());
```

**Calculating Information Content**

```python
import pandas as pd
import numpy as np

data = pd.read_csv("data/^TWII.csv")
column = data['Open']
value, counts = np.unique(column, return_counts=True)

prob = counts / len(column)

for i in range(len(value)) :
    information = -np.log2(prob[i])
    print("Symbol: ", value[i], "Information: ", information)
```

**Calculating Entropy (Discontinuous)**

```python
import pandas as pd
import numpy as np

data = pd.read_csv("data/^TWII.csv")
column = data['Open']

values, counts = np.unique(column, return_counts=True)
counts = counts[np.nonzero(counts)]

prob = []

for i in range(len(counts)):
    prob.append(counts[i] / len(column));
# Alternative : prob = counts / len(column)

def entropy(prob) :
    entropy = 0
    for i in range(len(prob)):
        entropy -= prob[i] * np.log2(prob[i]);
    return entropy

print(entropy(prob))

```

**Calculating Entropy by Using Bins(Continuous)**

```python
import pandas as pd
import numpy as np

data = pd.read_csv("data/canada.csv")
data.loc[:, 'Date'] = pd.to_datetime(data['Date'])
data['Close'] = pd.to_numeric(data['Close'], errors='coerce')
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
        'Symbol' : [f"{i}" for i in range(1, len(bin_edges))],
        'Bin Range': [f"[{bin_edges[i]:.4f}, {bin_edges[i+1]:.4f})" for i in range(len(bin_edges)-1)],
        'Frequency': binned_dist,
        'Probability': probs
    });
    probs = probs[np.nonzero(probs)]
    print(bin_table)
    entropy = 0
    for i in range(len(probs)):
        entropy -= probs[i] * np.log2(probs[i]);
    return entropy

print("Entropy :",  entropy(column, 12).round(4))
```

**NOTE :**

```python
    for i in range(len(prob)):
        entropy -= prob[i] * np.log2(prob[i]);

    **This portion may be written,**

    entropy = -np.sum(probs * np.log2(probs));
```

**Mutual Information**

```python
import pandas as pd
import numpy as np

# X
data = pd.read_csv("data/canada.csv");
X = data[['Date', 'Close']];
X.loc[:, 'Date'] = pd.to_datetime(X['Date'])
X['Close'] = pd.to_numeric(X['Close'], errors='coerce')
X.loc[:, 'Close'] = np.log(X['Close']) - np.log(X['Close'].shift(1));
X = X[X['Close'].notna()];
X.sort_values(by='Date', ascending=True, inplace=True)
X = X.dropna()

# Y
data2 = pd.read_csv("data/^TWII.csv");
Y = data2[['Date', 'Close']];
Y.loc[:, 'Date'] = pd.to_datetime(Y['Date'])
Y['Close'] = pd.to_numeric(Y['Close'], errors='coerce')

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
        'Symbol' : [f"{i}" for i in range(1, len(bin_edges))],
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



```

**Using Library function**

```python
import pandas as pd
import numpy as np
from scipy.stats import entropy
from sklearn.metrics import mutual_info_score

data = pd.read_csv("data/^TWII.csv")
bins = 100;

#X
X = data['Open']
X = X.dropna()
X_binned = np.histogram(X, bins)[0];

#Y
Y = data['Close']
Y = Y.dropna()
Y_binned = np.histogram(Y, bins)[0];

print(entropy(X_binned, base=2))
print(entropy(Y_binned, base=2))

mutual_info = mutual_info_score(X_binned,Y_binned)
print(mutual_info)
```

**Graph**

```python
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
```

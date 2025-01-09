import pandas as pd
import numpy as np

# X
data = pd.read_csv("newData/halla_climate.csv");
data['Date'] = pd.to_datetime(data['Date'])
data['Close'] = pd.to_numeric(data['Close'], errors='coerce')
data['Open'] = pd.to_numeric(data['Open'], errors='coerce')
data = data.dropna()


X = data[['Date', 'Close', 'Open']]
X = X.copy()
X.loc[:, 'Date'] = pd.to_datetime(X['Date'])
X = X[X['Close'].notna()];
X.sort_values(by='Date', ascending=True, inplace=True)
X = X.dropna()

# Y
data2 = pd.read_csv("newData/kyung_bang.csv");
data2['Date'] = pd.to_datetime(data2['Date'])
data2['Close'] = pd.to_numeric(data2['Close'], errors='coerce')
data2['Open'] = pd.to_numeric(data2['Open'], errors='coerce')
X = X[X['Close'].notna()];
data2 = data2.dropna()


Y = data2[['Date', 'Close', 'Open']];
Y = Y.copy()
Y.loc[:, 'Date'] = pd.to_datetime(Y['Date'])
Y.sort_values(by='Date', ascending=True, inplace=True)
Y = Y.dropna()

# Merge
XY = pd.merge(X, Y, on='Date', how='inner');
XY['Date'] = pd.to_datetime(XY['Date'])

print("Bins: 10")

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



# Entropy of halla_climate.csv 'Close' column:
print(f"Entropy of halla_climate.csv 'Close' column:")
unique_years = X['Date'].dt.year.unique()
unique_years = sorted(unique_years)

for year in unique_years:
    yearly_data = X[X['Date'].dt.year == year]
    yearly_column = np.log(yearly_data['Close']) - np.log(yearly_data['Close'].shift(1))
    yearly_column = yearly_column.dropna()   
    print(f" Entropy of {year}: {entropy(yearly_column, 10).round(6)}")

# Mutual information of halla_climate.csv 'Close' column with its 'Open' column:
print("\nMutual information of halla_climate.csv 'Close'  column with its 'Open' column:");
for year in unique_years:
    yearly_data = X[X['Date'].dt.year == year]
    print(f" Mutual Information of {year} : {mutualInformation(yearly_data['Close'], yearly_data['Open'], 10).round(6)}")


# Entropy of kyung_bang.csv 'Close' column:
print(f"\n\nEntropy of kyung_bang.csv 'Close' column:")
unique_years = Y['Date'].dt.year.unique()
unique_years = sorted(unique_years)

for year in unique_years:
    yearly_data = Y[Y['Date'].dt.year == year]
    yearly_column = np.log(yearly_data['Close']) - np.log(yearly_data['Close'].shift(1))
    yearly_column = yearly_column.dropna()   
    print(f" Entropy of {year}: {entropy(yearly_column, 10).round(6)}")

# Mutual information of kyung_bang.csv 'Close' column with its 'Open' column:
print("\nMutual information of kyung_bang.csv 'Close' column with its 'Open' column:");
for year in unique_years:
    yearly_data = Y[Y['Date'].dt.year == year]
    print(f" Mutual Information of {year} : {mutualInformation(yearly_data['Close'], yearly_data['Open'], 10).round(6)}")


# Mutual Information of halla_climate.csv 'Close' and kyung_bang.csv 'Close' columns:
print("\nMutual Information of halla_climate.csv 'Close' and kyung_bang.csv 'Close' columns:");


unique_years = XY['Date'].dt.year.unique()
unique_years = sorted(unique_years)

for year in unique_years:
    yearly_data = XY[XY['Date'].dt.year == year]
    print(f" Mutual Information of {year} : {mutualInformation(yearly_data['Close_x'], yearly_data['Close_y'], 10) : .6f}");


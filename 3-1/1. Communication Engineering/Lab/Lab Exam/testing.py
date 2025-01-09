import pandas as pd 
import numpy as np 
 
# X 
data = pd.read_csv("newData/halla_climate.csv"); 
data['Date'] = pd.to_datetime(data['Date']) 
 
X = data[['Date', 'Close']] 
X = X.copy() 
X.loc[:, 'Date'] = pd.to_datetime(X['Date']) 
X.loc[:, 'Close'] = np.log(X['Close']) - np.log(X['Close'].shift(1)); 
X = X[X['Close'].notna()]; 
X.sort_values(by='Date', ascending=True, inplace=True) 
X = X.dropna() 
 
# Y 
data2 = pd.read_csv("newData/hankook_tire.csv"); 
data2['Date'] = pd.to_datetime(data2['Date']) 
 
Y = data2[['Date', 'Close']]; 
Y = Y.copy() 
 
Y.loc[:, 'Date'] = pd.to_datetime(Y['Date']) 
Y['Close'] = pd.to_numeric(Y['Close'], errors='coerce') 
 
Y.loc[:, 'Close']  = np.log(Y['Close']) - np.log(Y['Close'].shift(1))    
Y = Y[Y['Close'].notna()]; 
Y.sort_values(by='Date', ascending=True, inplace=True) 
Y = Y.dropna() 
 
# Merge 
XY = pd.merge(X, Y, on='Date', how='inner'); 
 
print("\nMutual Information of daewooship_marin_eng.csv 'Close' and hankook_tire.csv 'Close"); 
print(X);
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
 
 
XY['Date'] = pd.to_datetime(XY['Date']) 
 
unique_years = XY['Date'].dt.year.unique() 
unique_years = sorted(unique_years) 
 
for year in unique_years: 
    yearly_data = data[data['Date'].dt.year == year] 
    yearly_column = np.log(yearly_data['Close']) - np.log(yearly_data['Close'].shift(1)) 
    yearly_column = yearly_column.dropna()    
    print(f" {year}, Entropy : {entropy(yearly_column, 12).round(4)}") 
 
for year in unique_years: 
    yearly_data = XY[XY['Date'].dt.year == year] 
    print(f"\n {year} Mutual Information: {mutualInformation(yearly_data['Close_x'], yearly_data['Close_y'], 12) : .4f}");
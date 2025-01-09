import pandas as pd
import numpy as np
from datetime import datetime

data = pd.read_csv("newData/dahaame-tec.csv")
data['Date'] = pd.to_datetime(data['Date'])
data['Close'] = pd.to_numeric(data['Close'], errors='coerce')
data.sort_values(by='Date', ascending=True, inplace=True)

def entropy(column, bins) :
    binned_dist, bin_edges = np.histogram(column, bins)
    probs = binned_dist / np.sum(binned_dist)
    probs = probs[np.nonzero(probs)]
    entropy = 0
    for i in range(len(probs)):
        entropy -= probs[i] * np.log2(probs[i]);
    return entropy


unique_years = data['Date'].dt.year.unique()
unique_years = sorted(unique_years)

for year in unique_years:
    yearly_data = data[data['Date'].dt.year == year]
    yearly_column = np.log(yearly_data['Close']) - np.log(yearly_data['Close'].shift(1))
    yearly_column = yearly_column.dropna()   
    print(f" {year}, Entropy : {entropy(yearly_column, 12).round(4)}")

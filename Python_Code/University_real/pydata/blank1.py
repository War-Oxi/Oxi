import pandas as pd

data = pd.read_csv('sample2.csv')
print(data)
data1 = data.dropna()
print(data1)

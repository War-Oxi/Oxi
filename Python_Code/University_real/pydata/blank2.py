import pandas as pd

data = pd.read_csv('sample2.csv')
print(data)
data1 = data.fillna(value=0)
print(data1)

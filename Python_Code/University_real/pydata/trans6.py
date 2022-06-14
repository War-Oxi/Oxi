import pandas as pd

data = pd.read_csv('sample.csv')
print(data)
data1 = data.replace(60, 0)
print(data1)

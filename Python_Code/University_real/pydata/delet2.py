import pandas as pd

data = pd.read_csv('sample.csv')
data1 = data.pop('영어')
print(data1)
print(data)

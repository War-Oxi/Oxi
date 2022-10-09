import pandas as pd

data = pd.read_csv('sample.csv')
data_1=data['국어']
data_2=data.국어
data_3=data[['국어','수학']]

print(data_1)
print(data_2)
print(data_3)
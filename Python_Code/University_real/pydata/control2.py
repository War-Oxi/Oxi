import pandas as pd

data = pd.read_csv('sample.csv')

data_1 = data['국어'].isin([78,98])
print(data_1)

data_2 = data[data['국어'].isin([78,98])]
print(data_2)

data_3 = data[data.isin([78,98])]
print(data_3)
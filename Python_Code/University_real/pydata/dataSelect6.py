import pandas as pd

data = pd.read_csv('sample.csv')
data_1 = data.loc[0]
data_2 = data.loc[0:5, ['국어','영어']]
print(data_1)
print(data_2)

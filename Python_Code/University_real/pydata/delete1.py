import pandas as pd

data = pd.read_csv('sample.csv')
data1 = data.drop(2)
print(data1)

data2 = data.drop([5,7])
print(data2)

data3 = data.drop('국어', axis=1)
print(data3)

data4 = data.drop(['국어','영어'], axis=1)
print(data4)



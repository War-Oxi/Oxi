import pandas as pd

data = pd.read_csv('sample.csv')
print(data.loc[1:3, ['국어','영어']])

data.loc[1:3, ['국어','영어']] = [[10,10],[20,20],[30,30]]
print(data.loc[1:3, ['국어','영어']])

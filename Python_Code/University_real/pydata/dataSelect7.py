import pandas as pd

data = pd.read_csv('sample.csv')
data_1 = data.iloc[0, 1:4]
data_2 = data.iloc[0:3, [1,3]]
data_3 = data.iloc[[2,4,6], [1,2]]

print(data_1)
print(data_2)
print(data_3)

data.loc
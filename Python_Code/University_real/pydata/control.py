import pandas as pd

data = pd.read_csv('sample.csv')

data_1 = data[data['수학']>=80]
print(data_1)

data_2 = data[(data['국어']>=80) & (data['수학']>=80) ]
print(data_2)

data_3 = data[(data['국어']>=80)| (data['수학']>=80) ]
print(data_3)

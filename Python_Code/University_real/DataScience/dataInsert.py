import pandas as pd

data = pd.read_csv('sample.csv')

col_name = 'Python'
col_value = [12, 23, 34, 45, 56, 67, 78, 89, 90, 21, 32, 43, 54, 65, 76, 87, 98, 99, 55, 44]
data.insert(2, col_name, col_value)
print(data)

append_data = pd.Series([100,200], ['국어', '컴퓨터'])
data1 = data.append(append_data, ignore_index=1)
print(data1)
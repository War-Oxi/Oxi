import pandas as pd

data = pd.read_csv('sample.csv')

append_data = pd.Series([100,200], ['국어', '컴퓨터'])
data1 = data.append(append_data, ignore_index=True)
print(data1)



col_name = '파이썬'
col_value = [100,90,95,90,93,70,85,81,73,65,88,79,73,77,50,66,88,97,50,70]
data.insert(2, col_name, col_value)
print(data)



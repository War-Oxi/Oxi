import pandas as pd

data = pd.read_csv('sample.csv')

col_name = '파이썬'
col_value = [100,90,95,90,93,70,85,81,73,65,88,79,73,77,50,66,88,97,50,70]
data.insert(2, col_name, col_value)
print(data)



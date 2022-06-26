import pandas as pd

data = pd.read_csv('sample.csv')
data_columns = data.columns
print(data_columns)

columns_len = len(data_columns)
print("데이터크기", columns_len)

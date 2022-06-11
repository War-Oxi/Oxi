import pandas as pd

data = pd.read_csv('sample.csv')
data_values = data.values
print(data_values)

values_len = len(data_values)
print("데이터크기", values_len)

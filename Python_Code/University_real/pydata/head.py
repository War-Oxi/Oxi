import pandas as pd

data = pd.read_csv('sample.csv')

data_head = data.head(3)
data_tail = data.tail(5)
print(data_head)
print(data_tail)





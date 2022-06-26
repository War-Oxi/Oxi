import pandas as pd

data = pd.read_csv('sample.csv')

data_rank = data.rank(axis=0, method='max', ascending=False)
print(data_rank)

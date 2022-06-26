import pandas as pd

data = pd.read_csv('sample.csv')

data_sort1 = data.sort_values(axis=0, by='국어', ascending=True)
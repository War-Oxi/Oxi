import pandas as pd

data = pd.read_csv('sample.csv')

#data_sort1 = data.sort_values(axis=0, by='영어', ascending=True)
#print(data_sort1)

data_sort2 = data.sort_values(axis=1, by=1, ascending=True)
print(data_sort2)





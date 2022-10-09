import pandas as pd

data = pd.read_csv('sample.csv')

sort_index1 = data.sort_index(axis=0, ascending=False)
print(sort_index1)

sort_index2 = data.sort_index(axis=1, ascending=True)
print(sort_index2)





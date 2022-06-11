import pandas as pd

data = pd.read_csv('sample.csv')

print(data.max(axis=0))
print(data.max(axis=1))
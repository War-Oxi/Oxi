import pandas as pd

data = pd.read_csv('sample.csv')

print(data.min(axis=0))
print(data.min(axis=1))
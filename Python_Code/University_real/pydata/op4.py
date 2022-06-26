import pandas as pd

data = pd.read_csv('sample.csv')

print(data.mean(axis=0))
print(data.mean(axis=1))
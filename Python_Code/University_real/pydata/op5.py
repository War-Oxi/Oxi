import pandas as pd

data = pd.read_csv('sample.csv')

print(data.median(axis=0))
print(data.median(axis=1))
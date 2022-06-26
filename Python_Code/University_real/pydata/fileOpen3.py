import pandas as pd

data = pd.read_csv('sample.csv')
data2 = data.set_index('학번', drop=False)
print(data2)
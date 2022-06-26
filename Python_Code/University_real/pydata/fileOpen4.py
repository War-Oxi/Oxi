import pandas as pd

data = pd.read_csv('sample.csv')
data = data.set_index('학번', drop=True)

data2=data.reset_index(drop=True)
print(data2)



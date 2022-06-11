import pandas as pd

data = pd.read_csv('sample.csv')
print(data.at[0, '국어'])

data.at[0, '국어'] = 100

print(data.at[0, '국어'])

import pandas as pd

data = pd.read_csv('sample.csv')

data_T = data.T
data_t = data.transpose()

print(data_T)




import pandas as pd

data = pd.read_csv('sample.csv')

data_describe = data.describe()
print(data_describe)





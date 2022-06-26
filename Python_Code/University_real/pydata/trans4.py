#여러개 행 값 변경

import pandas as pd

data = pd.read_csv('sample.csv')
print(data.loc[1:3, '국어'])

data.loc[1:3, '국어'] = [90,95,100]
print(data.loc[1:3, '국어'])

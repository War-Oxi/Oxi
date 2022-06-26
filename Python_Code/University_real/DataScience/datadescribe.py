import pandas as pd

data = pd.read_csv('sample.csv')

data_describe = data.describe()
print(data_describe) #mean은 평균값을 나타냄 std는 표준편차 min은 최소값
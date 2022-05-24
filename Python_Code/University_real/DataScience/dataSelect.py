import pandas as pd

data = pd.read_csv('sample.csv')
data_columns = data.columns
print(data)
print(data_columns)

columns_len = len(data_columns)
print("데이터 크기", data.size)
#
# data1 = pd.read.csv('sample.csv')
# data1_values = data1.values
# print(data1_values)
#
# values_len = len(data1_values)
# print("데이터 크기", values_len)

## 열 선택
data = pd.read_csv('sample.csv')
data_1 = data['국어']
data_2 = data.국어
data_3 = data[['국어', '수학']]

print(data_1, data_2, data_3)

## 행 선택
data = pd.read_csv('sample.csv')
data_1 = data.loc[0]
data_2 = data.loc[0:3, ['국어', '영어']]
data_3 = data.iloc[0:3, [1,3]] #정수형 문자열로 선택
data_3 = data.iloc[[2,4,6], [1,2,3]] #정수형 문자열로 선택
print(data_1)
print(data_2)
print(data_3)
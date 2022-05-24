import pandas as pd

# data_series = pd.Series([1,2,3,4,5,'A','B','C','가','나','다'])
# print(data_series)
# print(type(data_series))


# data_series2 = pd.Series([1.0, 2.0, 3.0])
# print(data_series2)
# print(type(data_series2))

data_series3 = pd.Series([1,2,3,4,5,'A','B','C','가','나','다'], index=['a','b','c','d','f','g','h','i','j','k','l'])
print(data_series3)

#! 인덱스 중복 가능 (index 'c'가 두 개)
data_series4 = pd.Series([1,2,3,4,5,'A','B','C','가','나','다'], index=['a','b','c','c','f','g','h','i','j','k','l'])
print(data_series4)
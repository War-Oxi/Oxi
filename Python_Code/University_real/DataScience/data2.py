import pandas as pd

data_series1 = pd.Series({'a':1, 'b':2, 'c':3, 'd':4, 'e':5})
print(data_series1)

#! 인덱스 중복 가능 (index 'c'가 두 개) but 덮어씌워짐
# 딕셔너리는 키 값을 중복할 수 없다
data_series2 = pd.Series({'a':1, 'b':2, 'c':3, 'c':4, 'e':5})
print(data_series2)
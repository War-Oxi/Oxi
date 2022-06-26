import pandas as pd

data = pd.read_csv('sample2.csv')

print(data)
data1 = data.dropna()  #데이터가 없는 행 제거
print(data1)

data2 = data.fillna(value=0)  ##NaN값에 해당하는 데이터를 0으로 채우기
print(data2)
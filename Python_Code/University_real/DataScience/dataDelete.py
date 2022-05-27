import pandas as pd

data = pd.read_csv('sample.csv')
print(data)
data1 = data.drop(2)
print(data1)

data2 = data.drop([1, 4])
print(data2)

# data3 = data.drop([1:4])  #에러 범위를 지정해서 drop시킬 수는 없을까?
# print(data3)

## '국어' 열 전체 삭제
data4 = data.drop('국어', axis=1)  # axix가 1일때는 열을 지정 0일떄는 행을 지정
print(data4)

data5 = data.drop(['국어', '영어'], axis=1)
print(data5)
print("====================================")
##pop 명령어를 사옹하면 원본파일까지 영향이 간다.
data6 = data.pop('영어')
print(data6)
print(data)


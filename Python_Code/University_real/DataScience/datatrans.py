import pandas as pd

data = pd.read_csv('sample.csv')
print(data)

##새로운 열을 추가하고 데이터 추가
data['수학'] = [100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 83, 93, 73, 1, 1, 1, 1, 1, 1]
print(data)
data['Programming'] = [12, 23, 34, 45, 56, 67, 78, 89, 90, 21, 32, 43, 54, 65, 76, 87, 98, 99, 55, 44]
print(data)

##인덱스 값에 해당하는 데이터 불러오기
##인덱스 값에 해당하는 데이터 값 변경하기
print(data.at[0, '국어'])
data.at[0, '국어'] = 100
print(data.at[0, '국어'])

##여러개 행 값 변경
print(data.loc[0:3, '국어'])
data.loc[0:3, '국어'] = [90, 80, 85, 77]
print(data.loc[0:3, '국어'])
print("======================================")
print(data.loc[1:3, ['국어','영어']])
data.loc[1:3, ['국어','영어']] = [[10,10], [20,20], [30,30]]
print(data.loc[1:3, ['국어','영어']])

print("======================================")
print(data)
data2 = data.replace(100, 0) #값에 해당하는 데이터의 값 변경 100 -> 0
print(data2)

##행과 열 바꾸기 행 -> 열, 열 -> 행
data_T = data.T #T = transpose의 약자
data_t = data.transpose()

print(data_t)
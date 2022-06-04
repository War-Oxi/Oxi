import pandas as pd

data = pd.read_csv("sample.csv")

#인덱스를 정렬
sort_index1 = data.sort_index(axis=0, ascending=False) #axis는 행과 열을 나타낼 때 쓰임 0=행 1=열 ascending=True(오름차순) ascending=False(내림차순)
print(sort_index1)

sort_index2 = data.sort_index(axis=1, ascending=True)
print(sort_index2)
import pandas as pd

data = pd.read_excel('../data.xlsx', engine="openpyxl")
data.rename(columns={'행정구역(시군구)별':'년도'}, inplace=True)
data.iat[0, 0] = "인구"

print(data)

data = data.set_index('년도')
# data_T = data.transpose()
data_T = data.T
#10행과 11행은 기능이 같음

data1 = data_T['전국'][data_T['인구'] == "총인구수 (명)"]
print(data_T)
print(data1)


data2 = data.transpose()
data2 = data.replace("총인구수 (명)", "전체", inplace=True)
data2 = data.replace("남자인구수 (명)", "남", inplace=True)
data2 = data.replace("여자인구수 (명)", "여", inplace=True)


print(data2)

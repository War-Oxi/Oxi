import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_excel('data.xlsx')
data.rename(columns={'행정구역(시군구)별':'년도'}, inplace=True)

data.iat[0,0]="인구"

data = data.set_index('년도')

data.replace("총인구수 (명)", "전체", inplace=True)
data.replace("남자인구수 (명)", "남", inplace=True)
data.replace("여자인구수 (명)", "여", inplace=True)

column1 = data.columns
column2 = data.loc['인구']

#data_T = data.transpose()
data_T = data.T

list_column = list(column1)
count = len(list_column)

for c in range(count):
    temp = list_column[c].replace(".1", "")
    temp = temp.replace(".2", "")
    list_column[c] = temp

data_T.index = list_column

data1 = data_T['경기도'][data_T['인구']=="남"]

plt.figure(num="인구 차트")
plt.rcParams.update({'font.family':'malgun gothic', 'font.size':12})
plt.title("연도별 경기도 남자 인구수")

ax=plt.gca()
data1.plot(kind='line', ax=ax, marker='o')
plt.xlabel("연도")
plt.ylabel("남자인구수")

plt.show()
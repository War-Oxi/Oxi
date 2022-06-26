# DataFrame 라인 차트 실행
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('sample.csv')

plt.figure(num="성적 그래프")

plt.rcParams.update({'font.family':'AppleGothic','font.size':12})

plt.title("학번별 성적")

plt.xlabel("학번")
plt.ylabel("성적")

# plt 적용, 한개의 화면에서 나타나도록 하기 위한 axes 설정
ax = plt.gca()

columns = ['국어','영어','수학']

data.plot(kind='line', x='학번', y=columns, marker='o')

plt.show()
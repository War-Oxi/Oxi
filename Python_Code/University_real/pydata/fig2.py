import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('sample.csv')

plt.figure(num="성적 그래프")

plt.rcParams.update({'font.family':'malgun gothic', 'font.size':12})
plt.title("학번별 성적")

ax = plt.gca()

xcolumns = ['학번','학번','학번']
ycolumns = ['국어','영어','수학']

color = ['#2091FF', '#99AACC', '#FF00FF', '#00FFFF', '#0000FF', '#000000']
data.plot(kind='scatter', x='학번', y='국어', ax=ax, color=color[3], s=10)
data.plot(kind='scatter', x='학번', y='영어', ax=ax, color=color[4], s=20)
data.plot(kind='scatter', x='학번', y='수학', ax=ax, color=color[5], s=30)

plt.xlabel("학번")
plt.ylabel("성적")

plt.show()


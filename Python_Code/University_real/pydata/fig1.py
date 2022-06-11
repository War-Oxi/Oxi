import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('sample.csv')

plt.figure(num="성적 그래프")
plt.rcParams.update({'font.family':'malgun gothic', 'font.size':12})
plt.title("학번별 성적")

plt.xlabel("학번")
plt.ylabel("성적")

ax = plt.gca()

columns = ['국어', '영어', '수학']
data.plot(kind='bar', x='학번', y=columns, ax=ax, stacked=True)
plt.show()

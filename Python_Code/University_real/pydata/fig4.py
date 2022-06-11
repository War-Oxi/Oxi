import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('sample.csv')
data = data.drop('학번', axis=1)

plt.figure(num="히스토그램")

plt.rcParams.update({'font.family':'malgun gothic', 'font.size':12})
plt.title("과목별 점수 빈도")

ax = plt.gca()

data.plot(kind='hist', by=None, bins=20, ax=ax, alpha=0.5, edgecolor='blue', linewidth=2)
plt.xlabel("과목별 성적")
plt.ylabel("빈도수")
plt.show()


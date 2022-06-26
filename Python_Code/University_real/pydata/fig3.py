import pandas as pd
import matplotlib.pyplot as plt

data = pd.DataFrame({'mass':[0.330, 4.87, 5.97], 'radius':[2439.7, 6051.8, 6378.2]})
index=['Mercury', 'Venus', 'Earth']

plt.figure(num="파이 차트")

plt.rcParams.update({'font.family':'apple gothic', 'font.size':12})
plt.title("행성 크기 비교")

ax = plt.gca()

data.plot(kind='pie', y='radius', ax=ax)
plt.show()


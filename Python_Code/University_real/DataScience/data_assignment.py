import pandas as pd

data = pd.read_csv('sample.csv')


def rating(avg):
    rate = "T"
    if avg >= 90:
        return "A"
    elif avg >= 80:
        return "B"
    else:
        return "C"


data2 = data.copy()
data2['평균'] = (data['국어'] + data['영어'] + data['수학']) / 3
data2['등급'] = "R"
print(data2)
for i in range(0, 20):
    data2['등급'][i] = rating(data2['평균'][i])
print(data2)
# print(data)

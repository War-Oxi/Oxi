<<<<<<< Updated upstream
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
for i in range(0, 20):
    data2['등급'][i] = rating(data2['평균'][i])
print(data2)
=======
import pandas as pd

data = pd.read_csv('sample.csv')
def Func(row):
    if(row > 90):
        return 'A'
    elif(row>80):
        return 'B'
    else:
        return 'C'

data['총합'] = data['국어']+data['영어']+data['수학']
data['평균'] = data['총합']/3
data['학점'] = data['평균'].apply(Func)
data['등수'] = data['평균'].rank()
data = data.sort_values('등수')
data = data.set_index('등수')

print(data)
>>>>>>> Stashed changes

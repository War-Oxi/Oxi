import pandas as pd

data = pd.read_csv('sample.csv')

def func(row):
    if row >= 90:
        return 'A'
    elif row >= 80:
        return 'B'
    elif row >= 70:
        return 'C'
    elif row >= 60:
        return 'D'
    else:
        return 'F'
##apply()함수의 쓰임 알아보기
data['성적'] = data['수학'].apply(func)
print(data)
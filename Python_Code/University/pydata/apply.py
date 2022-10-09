import pandas as pd

data = pd.read_csv('sample.csv')

def func(row):
    if row >= 90:
        return 'A'
    elif row >= 80:
        return 'B'
    else:
        return 'C'

data['성적'] = data['수학'].apply(func)
print(data)



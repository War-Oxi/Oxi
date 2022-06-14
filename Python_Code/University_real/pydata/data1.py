import pandas as pd

data_series1 = pd.Series([1,2,3,4,5,'A','B','C','가','나','다'],['a','b','c','c','e','f','g','h','i','j','k'])
print(data_series1)

data_series2 = pd.Series([1,2,3,4,5,'A','B','C','가','나','다'], index=['a','b','c','c','e','f','g','h','i','j','k'])
print(data_series2)

import pandas as pd

## .csv file open & read
# data=pd.read_csv("sample.csv")
# print(data)

# #첫 번째 열이 공백이므로, NaN값이 출력
# data2=pd.read_csv("sampleBlank.csv")
# print(data2)

## .xlsx Excel 파일 open & read
# data3 = pd.read_excel("sample.xlsx")
# print(data3)

data4 = pd.read_csv("sample.csv")
# data4 = data4.set_index('학번', drop=False) # 학번을 유지하고 인덱스를 학번으로.
data4 = data4.set_index('학번', drop=True) # 학번이 사라지고 인덱스로 변환됨
data4 = data4.reset_index('학번', drop=False)
# data4 = data4.reset_index('학번', drop=True)
print(data4)
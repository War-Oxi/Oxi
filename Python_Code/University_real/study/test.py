dic = {'name':'Hong', 'address':'seoul'}
dic['fuck'] = 'you'

dic['phone'] = '01088135460'

dic.pop('phone')

print(dic['name'])

print(list(dic.keys()))
print(list(dic.values()))
print(dic.items())
print(dic)

s1 = {1,2,3,4,5,6,7,8}
s1.add('B')
s1.remove(7)
s1.update([10,22,33,44,55])
s1.remove('B')

print(s1)

str = "hello python"
str1 = str.replace('o', 'A')

print(str1)
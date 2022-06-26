a=[1,2,3]
a.append([4, 5])
print("a.append([4,5])결과 ->", a)

a.insert(3,5)
print("a.insert(3,5) 결과 ->", a)

a.pop(0)
print("a.pop(0) 결과 ->", a)

a.extend([4,5])
print("a.extend([4, 5]) 결과 ->", a)

b = [6,7,8]
print('b =>', b)
a.append(b)
print('a.append(b) 결과 ->', a)

print('sum(b)결과 ->', sum(b))
print(sum(a[3]))

dic = {'name':'hong', 'phone':'01088135460'}
print(dic)
dic.update({'address':'korea'})
print(dic)
del dic['address']
print(dic)
import pickle
def func():
    # global a, b, c
    print(1)

pickle.dump(func, open("pickle.pic", 'wb'))
load_data = pickle.load(open("pickle.pic", 'rb'))

print(load_data)
print(type(load_data))
load_data()
def FileWrite():
    fileout = open("./phones1.txt", 'w', encoding="utf-8")
    fileout.write("성춘향 010-2345-6789\n")
    fileout.write("이몽룡 010-1010-4585\n")
    fileout.close()


def FileAppend():
    fileout = open("./phones1.txt", "a", encoding="utf-8")
    fileout.write("변학도 010-9876-5432\n")
    fileout.close()


def FileRead():
    filein = open("./phones1.txt", 'r', encoding="utf-8")
    readall = filein.read()
    print(readall)
    print(type(readall))
    filein.close()
    return readall


def FileReadLines():
    filein = open("./phones1.txt", "r", encoding="utf-8")
    readall = filein.readlines()
    print(readall)
    filein.close()

def FileReadLine():
    filein = open("./phones1.txt", "r", encoding="utf-8")
    read_line = filein.readline().rstrip()
    while read_line != "":
        print(read_line)
        read_line = filein.readline().rstrip()
    # print(read_line)
    filein.close()

def With_As():
    with open("phones1.txt", "r", encoding='utf-8') as file:
        str = file.read()
        print(str)
        str = str.rstrip()
        print(str.split('\n'))

def RandomFileAccess():
    f = open('workfile', 'w')
    f = open('workfile', 'rb+')
    f.write(b'0123456789abcdef')
    print(f.seek(5))
    print("=====>{}".format(f.tell()))
    print(f.read(1))
    print("=====>{}".format(f.tell()))
    print(f.seek(-3, 2))
    print("=====>{}".format(f.tell()))
    print(f.read(1))
    print("=====>{}".format(f.tell()))
    f.close()

def Pickling():
    import pickle
    Pres = {"Kennedy" : 35, "Obama": 44}

    pickle.dump(Pres, open("pres.pic", "wb"))

    Pres2 = pickle.load(open("pres.pic", "rb"))
    Pres2['Trump'] = 45

    pickle.dump(Pres2, open("pres2.txt", "wb"))
    print(Pres)
    print(Pres2)

def Pickling_test():
    import pickle
    input_test = input("기록할 글자를 입력하세요")
    pickle.dump(input_test, open("pres.pic", "wb"))
    file_out_put = pickle.load(open("pres.pic", "rb"))
    print(file_out_put)

def Chracter_SwapCase(A): #대문자 소문자 상호 변환
    print(chr(ord(A) ^ 32))
    # print(type(ord(A)))

def Prime_Num(Num): #소수
    if Num == 2:
        return True
    for i in range(2, int(Num/2+1)):
        if Num % i == 0:
            return False
    return True

# sum = lambda x, y: (x+y, x*y)

def fileNumCount():
    with open('test.txt', 'r') as file:
        str = file.read().rstrip()
        str_list = str.split(" ")
        str_list = list(map(int, str_list))
        str_list.sort()
        count = 0
        for i in range(1,46):
            print("숫자{}의 개수 => {}".format(i, str_list.count(i)))
            count += str_list.count(i)
        print(count)
        print(str_list)

def usePickling():
    import pickle

    Pres = {"Kennedy": 35, "Obama": 44}

    pickle.dump(Pres, open("pres.pic", 'wb'))

    Pres2 = pickle.load(open("pres.pic", 'rb'))
    Pres2['Trump'] = 45

    pickle.dump(Pres2, open("pres2.pic", 'wb'))
    print(Pres)
    print(type(Pres2))
    print(Pres2)

# usePickling()
a = [1,2,3,4]
a.reverse()
print(a)
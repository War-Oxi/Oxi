def insert_data(position, friend) :
    if position < 0 or position > len(katok):
        print("데이터를 삽입할 범위를 벗어났습니다.")
        return
    katok.append(None)
    kLen = len(katok)
    for i in range(kLen -1, position, -1):
        katok[i] = katok[i-1]
        katok[i-1] = None
    katok[position] = friend

def insertKatok(data) :
    flag = True
    for i in range(0, len(katok)):
        if(katok[i][1] <= data[1]):
            insert_data(i, data)
            flag = False
            break
    if(flag):
        insert_data(len(katok), data)

katok = [('다현', 200), ('정연', 150), ('쯔위', 90), ('사나', 30), ('지효', 15)]

if __name__ == "__main__" :
    while (True) :
        name = input("추가할 친구--> ")
        if(name == "-1"):
            print("프로그램을 종료합니다.")
            break
        count = int(input("카톡 횟수--> "))
        data = (name, count)
        insertKatok(data)
        print(katok)
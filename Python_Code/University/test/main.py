def insertKatok(data):
    global katok
    end = len(katok)
    for i in range(0, end):
        if data[1] >= katok[i][1]:
            insert_data(i, data)
            break


def insert_data(pos, end) :
    if pos < 0 or pos > len(katok):
        print("데이터 범위를 벗어남")
        return
    katok.append(None)
    kLen = len(katok)
    for i in range(kLen - 1, pos, -1):
        katok[i] = katok[i - 1]
        katok[i - 1] = None
    katok[pos] = end

katok = [('다현',200), ('정연',150), ('쯔위',90), ('사나',30), ('지효',15)]
name = input("추가할 친구--> " )
count = int(input("카톡 횟수--> "))
data = (name, count)
insertKatok(data)
print(katok)
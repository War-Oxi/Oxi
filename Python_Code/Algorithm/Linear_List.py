## 함수 선언 ##
def insert_data(position, friend):
    katok.append(None)
    for num in range(len(katok)-1, position, -1):
        katok[num] = katok[num-1]
    katok[position] = friend

    # katok.append(friend)

def find_and_insert_data(friend, k_count):

def add_data(friend):
    katok.append(friend)

def delete_data(friend):
    friend_index = katok.index(friend)
    for num in range(friend_index, len(katok)-1):
        katok[num] = katok[num+1]
    del(katok[len(katok)-1])
## 전역 변수 선언 ##
katok = []
select = -1
## 메인 코드 ##
if __name__ == "__main__":
    add_data('다현')
    add_data('정연')
    add_data('쯔위')
    add_data('사나')
    add_data('지효')
    while (select != 4):
        select = int(input("선택하세요(1:추가, 2:삽입, 3:삭제, 4:종료) -->"))

        if(select == 1):
            data = input("추가할 데이터--> ")
            add_data(data)
            print(data, "추가 완료")
            print("결과 --> ", katok)
        elif(select == 2):
            index = int(input("삽입 위치-->"))
            data = input("추가할 데이터-->")
            insert_data(index, data)
            print(data, "추가 완료")
            print("결과 --> ", katok)
        elif(select == 3):
            data = input("삭제할 데이터-->")
            delete_data(data)
            print(data, "삭제 완료")
            print("결과 --> ", katok)
        else:
            break

    print("==========프로그램 종료=========")
    print("=============================")
    print("결과 --> ", katok)

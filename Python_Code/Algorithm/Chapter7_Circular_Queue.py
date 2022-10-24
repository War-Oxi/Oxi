def isQueueFull():
    global SIZE, circular_queue, front, rear
    if (rear+1) % SIZE == front:
        return True
    else:
        return False

def isQueueEmpty():
    global SIZE, circular_queue, front, rear
    if front == rear:
        return True
    else:
        return False

def enQueue(data):
    global SIZE, circular_queue, front, rear
    if isQueueFull():
        print("큐가 꽉 찼습니다")
        return
    rear = (rear+1) % SIZE
    circular_queue[rear] = data

def deQueue():
    global SIZE, circular_queue, front, rear
    if isQueueEmpty():
        print("큐가 비었습니다.")
        return
    front = (front + 1) % SIZE
    data = circular_queue[front]
    circular_queue[front] = None
    return data

SIZE = int(input("큐 크기를 입력하세요 ==> "))
circular_queue = [None for _ in range(SIZE)]
front = rear = 0

if __name__ == "__main__":
    select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")

    while select != 'X':
        if select == 'I':
            data = input("입력할 데이터 ==> ")
            enQueue(data)
            print("큐 상태 : ", circular_queue)
            print("front : ", front, ", rear : ", rear)
        elif select == 'E':
            data = deQueue()
            print("추출된 데이터 ==> ", data)
            print("큐 상태 : ", circular_queue)
            print("front : ", front, ", rear : ", rear)
        else:
            print("잘못된 입력")

        select = input("삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ")
print("프로그램 종료")
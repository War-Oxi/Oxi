def isQueueFull():
    global SIZE, queue, front, rear
    if rear != SIZE-1:
        return False
    elif (rear == SIZE-1) and (front == -1):
        return True
    else:
        for i in range(front+1, SIZE):
            queue[i-1] = queue[i]
            queue[i] = None
        front -= 1
        rear -= 1
        return False

def isQueueEmpty():
    global SIZE, queue, front, rear
    if front == rear:
        return True
    else:
        return False

def enqueue(data):
    global SIZE, queue, front, rear
    if isQueueFull():
        print("큐가 꽉 찼습니다.")
        return
    rear += 1
    queue[rear] = data

def dequeue():
    global SIZE, queue, front, rear
    if isQueueEmpty():
        print("큐가 비었습니다")
        return None
    front += 1
    data = queue[front]
    queue[front] = None
    return data

SIZE = 3
queue = [None for _ in range(SIZE)]
front = rear = -1

if __name__ == "__main__":
    enqueue(1)
    enqueue(1)
    enqueue(1)
    dequeue()
    dequeue()
    dequeue()
    enqueue(5)
    enqueue(6)
    enqueue(7)
    dequeue()
    dequeue()
    dequeue()
    dequeue()
    enqueue(7)
    enqueue(7)
    enqueue(7)
    enqueue(7)
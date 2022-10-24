"""
1~45 숫자 6개를 뽑는 로또 추첨 프로그램을 작성한다.
뽑은 숫자는 순서대로 단순 연결 리스트로 저장한다
"""
import random

class Node:
    def __init__(self):
        self.data = None
        self.link = None

def printNodes(start):
    current = start
    while current.link != None:
        print(current.data, end=" ")
        current = current.link
    print()

def insertNode(insert_data):
    global head, current, pre

    node = Node()
    node.data = insert_data
    if head == None:
        head = node
        return

    if head.data > insert_data:
        node.link = head
        head = node
        return

    current = head
    while current.link != None:
        pre = current
        current = current.link
        if current.data > insert_data:
            pre.link = node
            node.link = current
            return

    current.link = node

def findNumber(num):
    global head, current, pre

    if head == None:
        return False
    current = head
    if current.data == num:
        return True
    while current.link != None:
        current = current.link
        if current.data == num:
            return True
    return False

head, current, pre = None, None, None

if __name__ == "__main__":
    lottoCount = 0
    while True:
        lotto = random.randint(1,45)
        if findNumber(lotto):
            continue
        lottoCount += 1
        insertNode(lotto)
        if lottoCount > 6:
            break

    printNodes(head)
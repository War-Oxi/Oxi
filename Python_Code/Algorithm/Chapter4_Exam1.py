# 사용자가 이름과 이메일을 입력하면 이메일 순서대로 단순 연결 리스트를 생성하는 프로그램을 작성.
"""
클래스 선언 부분
"""
class Node:
    def __init__(self, data=None, link=None):
        self.data = data
        self.link = link

"""
함수선언부분
"""
def printNodes(start):
    current = start
    while current != None:
        print(current.data, end=' ')
        current = current.link
    print()


def insertNode(insert_data):
    global head, current, pre

    node = Node()
    node.data = insert_data
    #처음 삽입
    if head == None:
        head = node
        return

    if head.data[1] > insert_data[1]:
        node.link = head
        head = node
        return
    #중간 삽입
    current = head
    while current.link != None:
        pre = current
        current = current.link
        if current.data[1] > insert_data[1]:
            pre.link = node
            node.link = current
            return
    #마지막 삽입
    current.link = node
'''
전역변수 선언 부분
'''

head, current, pre = None, None, None
'''
메인 함수 부분
'''
if __name__ == "__main__":
    while True:
        name = input("이름 --> ")
        if name == "" or name == None:
            break
        email = input("이메일 --> ")
        insertNode([name, email])
        printNodes(head)


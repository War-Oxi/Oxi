## 함수 및 클래스 선언 부분 ##

class Node:
    def __init__(self, data=None, link=None):
        self.data = data
        self.link = link

    def Print(self):
        print(self.data, self.link)

def Print_Nodes(head):
    current = head
    if current is None:
        return
    while current.link is not None:
        print(current.data, end=' ')
        current = current.link
    print(current.data)


def Insert_Node_Before(find_data, insert_data):
    global singly_linked_list, head, current, pre
    node = Node(insert_data)

    # if len(singly_linked_list) == 0:
    if head is None:
        # singly_linked_list.append(node)
        node.link = head
        head = node
        return

    # singly_linked_list.append(node)
    if head.data == find_data:
        node.link = head
        head = node
        return

    current = head
    while current.link is not None:
        pre = current
        current = current.link
        if current.data == find_data:
            pre.link = node
            node.link = current
            return

    current.link = node


def Insert_Node_After(find_data, insert_data):
    global singly_linked_list, head, current, pre
    node = Node(insert_data)

    if head is None:
        node.link = head
        head = node
        return

    if head.data == find_data:
        node.link = head.link
        head.link = node
        return

    current = head
    while current.link is not None:
        pre = current
        current = current.link
        if pre.data == find_data:
            pre.link = node
            node.link = current
            return

    current.link = node

def Delete_Data(data):
    global singly_linked_list, head, current, pre
    current = head
    if head.data == data:
        head = head.link
        del(current)
        return

    while current.link is not None:
        pre = current
        current = current.link
        if current.data == data:
            pre.link = current.link
            del(current)
            return

def Find_Data(data):
    global singly_linked_list, head, current, pre

    current = head
    if current.data == data:
        return current
    while current.link != None:
        current = current.link
        if current.data == data:
            return current
    return Node()

## 전역 변수 선언 부분 ##
head, current, pre = None, None, None
# singly_linked_list = []

## 메인 코드 부분 ##
if __name__ == "__main__":
    Insert_Node_Before("바보", "바보1")
    Insert_Node_Before("바보1", "바보2")
    Insert_Node_After("바보2", "바보3")
    Insert_Node_Before("바보2", "바보4")
    Insert_Node_After("바보4", "바보5")
    Insert_Node_After("바보1", "바보6")
    # Delete_Data("바보1")
    Delete_Data("바보4")
    # print(Find_Data("바보5").data)
    # print(Find_Data("바보6").data)

    # Delete_Data("바보3")
    # Delete_Data("바보2")
    # Delete_Data("바보5")
    # print(head.link.data)
    # print(singly_linked_list)
    Print_Nodes(head)
    # print(len(singly_linked_list))

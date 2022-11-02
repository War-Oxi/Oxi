class KeyValue:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def printKeyValue(self):
        print("(%s, %s)" % (self.key, self.value))

class BSTNode:
    def __init__(self, val=None):
        self.left = None
        self.right = None
        self.keyvalue = val

    def insertNode(self, keyvalue):
        if self.keyvalue.key == keyvalue.key:
            return
        elif keyvalue.key < self.keyvalue.key:
            if self.left:
                self.left.insertNode(keyvalue)
                return
            self.left = BSTNode(keyvalue)
        else:
            if self.right:
                self.right.insertNode(keyvalue)
                return
            self.right = BSTNode(keyvalue)

    def searchNode(self, key):
        if key == self.keyvalue.key:
            print("찾은 데이터:", end=" ")
            self.keyvalue.printKeyData()
            return self.keyvalue
        elif key < self.keyvalue.key:
            if self.left is None:
                return None
            return self.left.searchNode(key)
        else:  # key > self.keyvalue.key:
            if self.right is None:
                return None
            return self.right.searchNode(key)

    @staticmethod
    def minValueNode(node):
        min_larger_node = node
        while min_larger_node.left is not None:
            min_larger_node = min_larger_node.left
        return min_larger_node

    def deleteNode(self, key):
        if self is None:
            return self
        if key < self.keyvalue.key:
            if self.left:
                self.left = self.left.deleteNode(key)
        elif key > self.keyvalue.key:
            if self.right:
                self.right = self.right.deleteNode(key)
        else:
            if self.right is None and self.left is None:
                del(self)
                return None
            if self.right is None:
                temp = self.left
                del(self)
                return temp
            if self.left is None:
                temp = self.right
                del(self)
                return temp

            # Here, both right and left are not None
            # (smallest in the right subtree)
            min_larger_node = BSTNode.minValueNode(self.right)
            self.keyvalue = min_larger_node.keyvalue
            self.right = self.right.deleteNode(min_larger_node.keyvalue.key)
        return self

    def printNode(self, depth, which):
        if self.left is not None:
            self.left.printNode(depth+1, "left")
        print("depth %d, %s: " % (depth, which), end='')
        self.keyvalue.printKeyValue()
        if self.right is not None:
            self.right.printNode(depth+1, "right")


class BST:
    def __init__(self):
        self.root = None

    def printAll(self):
        print("--------------------")
        if self.root is not None:
            self.root.printNode(1, "root")


    def search(self, key):
        current = self.root
        while current is not None:
            if key == current.keyvalue.key:
                print("찾은 데이터:", end=" ")
                current.keyvalue.printKeyData()
                return current.keyvalue
            elif key < current.keyvalue.key:
                current = current.left
            else:
                current = current.right
        print("Key %s 에 해당하는 것이 없습니다" % key)
        return None

    def searchRecursive(self, key):
        if self.root is not None:
            return self.root.searchNode(key)
        return None

    def insert(self, keyvalue):
        if self.root is None:
            self.root = BSTNode(keyvalue)
            return
        current = self.root
        while current is not None:
            if current.keyvalue.key == keyvalue.key:
                return # failed to insert for the existing data
            elif keyvalue.key < current.keyvalue.key:
                if current.left is not None:
                    current = current.left
                    continue
                current.left = BSTNode(keyvalue)
                return
            else: #keyvalue.key > current.keyvalue.key:
                if current.right is not None:
                    current = current.right
                    continue
                current.right = BSTNode(keyvalue)
                return

    def insertRecursive(self, keyvalue):
        if self.root is None:
            self.root = BSTNode(keyvalue)
            return
        self.root.insertRecursive(keyvalue)

    def delete(self, key):
        print("Key %s를 삭제" % key)
        current = self.root
        parent = None
        while current is not None:
            if key < current.keyvalue.key:
                parent = current
                current = current.left
            elif key > current.keyvalue.key:
                parent = current
                current = current.right
            else: # key == current.keyvalue.key
                if current.left is not None and current.right is not None:
                    # 오른쪽에서 가장 작은 값는 노드 찾기
                    parent = current
                    min_larger_node = current.right
                    while min_larger_node.left is not None:
                        parent = min_larger_node
                        min_larger_node = min_larger_node.left

                    current.keyvalue = min_larger_node.keyvalue
                    if min_larger_node == current.right:
                        current.right = min_larger_node.right
                    else:
                        parent.left = min_larger_node.right
                    del(min_larger_node)
                elif current.left is None and current.right is None:
                    if parent is None: # current == self.root
                        self.root = None
                    elif parent.left == current:
                        parent.left = None
                    else:
                        parent.right = None
                    del(current)
                else: #Only one between left and right is None
                    child = None
                    if current.left is not None: # current.right is None:
                        child = current.left
                    else: # current.left is None and current.right is not None:
                        child = current.right
                    if parent is None: # current == self.root
                        self.root = child
                    elif parent.left == current:
                        parent.left = child
                    else:
                        parent.right = child
                    del(current)

                return
        print("Key %s가 없어 지울 수 없음" % key)


    def deleteRecursive(self, key):
        if self.root is not None:
            self.root = self.root.deleteNode(key)


data = [
    ("박혁거세", "010-1111-8888"),
    ("김수로", "010-1111-6666"),
    ("궁예", "010-1111-5555"),
    ("김유신", "010-1111-7777"),
    ("을지문덕", "010-1111-1111"),
    ("이순신", "010-1111-3333"),
    ("신사임당", "010-1111-4444"),
    ("홍길동", "010-1111-2222") ]

tree = BST()

#데이터 초기화
for d in data:
    tree.insert( KeyValue(d[0],d[1]) )

tree.printAll()

tree.delete("박혁거세")
tree.delete("신사임당")
tree.delete("궁예")
tree.delete("을지문덕")
tree.delete("이순신")
tree.printAll()
tree.delete("홍길동")
tree.printAll()
tree.delete("김수로")
tree.printAll()
tree.delete("김유신")

#마지막까지 모든 데이터 삭제 후 확인
tree.printAll()


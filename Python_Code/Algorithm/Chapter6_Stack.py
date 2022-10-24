class Stack():
    def __init__(self, size=5):
        self.size = size
        self.stack = list(0 for _ in range(size))
        self.top = 0

    def Push(self, data):
        if self.top == self.size:
            print("stack is full")
        else:
            self.stack[self.top] = data
            self.top += 1

    def Pop(self):
        if self.top == 0:
            print("stack is empty")
            return
        else:
            self.top -= 1
            return self.stack[self.top]

# print(stack1.top)
# print(len(stack1.stack))
stack1 = Stack(2)
stack1.Push(5)
stack1.Push(6)
stack1.Push(6)
print(stack1.Pop())
print(stack1.Pop())
print(stack1.Pop())
print(stack1.Pop())

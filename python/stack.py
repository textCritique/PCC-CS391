class stack:
    def __init__(self):
        self.stack = []
        self.top = -1
    def isEmpty(self):
        return self.top == -1
    def pop(self):
        if self.top == -1:
            raise ValueError("Already empty")
        self.top -= 1
        popped = self.stack.pop()
        return popped
    def push(self,data):
        self.top += 1
        self.stack.append(data)
    def peek(self):
        if self.top == -1:
            raise ValueError("Empty")
        return self.stack[self.top]


stk = stack()
stk.push(1)
stk.push(2)
stk.push(3)
print(stk.pop())
print(stk.pop())
print(stk.pop())
print(stk.pop())

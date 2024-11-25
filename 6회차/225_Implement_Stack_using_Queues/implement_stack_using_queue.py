class MyStack:

    def __init__(self):
        self.queue = [0] * 101
        self.tmp = [0] * 101
        self.size = 0

    def push(self, x: int) -> None:
        self.queue[self.size+1] = x
        self.size += 1

    def pop(self) -> int:
        back = self.queue[self.size]
        
        for i in range(self.size) :
            self.tmp[i] = self.queue[i]
        self.size -= 1
        self.queue = self.tmp
        
        self.tmp = {}
        return back

    def top(self) -> int:
        return self.queue[self.size]

    def empty(self) -> bool:
        return self.size == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
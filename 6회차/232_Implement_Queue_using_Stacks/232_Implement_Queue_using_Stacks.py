class MyQueue:

    def __init__(self):
        self.main_stack = [] ## push
        self.sub_stack = [] ## pop, peek
        

    def push(self, x: int) -> None:
        self.main_stack.append(x)
        

    def pop(self) -> int:
        ## main -> sub로 뒤집어서 옮김
        if not self.sub_stack: ## 어차피 순서대로니까 pop은 sub_stack에 있는 것 먼저 처리. sub_stack이 비면 아래와 같이 main_stack에서 가져와서 동기화
            while self.main_stack:
                self.sub_stack.append(self.main_stack.pop())

        return self.sub_stack.pop() if self.sub_stack else None


    def peek(self) -> int:
        if not self.sub_stack:
            while self.main_stack:
                self.sub_stack.append(self.main_stack.pop())

        return self.sub_stack[-1] if self.sub_stack else None
        

    def empty(self) -> bool:
        return not self.main_stack and not self.sub_stack
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
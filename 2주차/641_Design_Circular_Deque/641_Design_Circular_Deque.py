# CircularDeque
# 1. 초기화 : 크기 k의 빈 배열 arr 생성, front = -1, rear = 0
# 2. 첫번째 요소 삽입 : index 0에 값이 삽입되고, front = 0, rear = 0
# 3. insertFront : 
#     3-1. deque가 Full인지 확인
#     3-2. front == 0이면 front를 배열의 마지막 인덱스로 이동
#     3-3. front != 0이면 front를 1만큼 감소시키고 arr[front] = value
# 4. insertLast :
#     4-1. deque가 Full인지 확인
#     4-2. rear == k-1이면 rear = 0으로 초기화
#     4-3. rear != k-1이면 rear를  1만큼 증가시키고 arr[rear] = value
# 5. deleteFront : 
#     5-1. deque가 Empty인지 확인
#     5-2. 요소가 하나만 있는 경우 front = -1, rear = -1
#     5-3. 요소가 둘 이상인 경우 front = (front + 1)%k 인덱스 배열 넘어서면 다시 0으로 돌아오도록 함
# 6. deleteLast : 
#     6-1. deque가 Empty인지 확인
#     6-2. 요소가 하나만 있는 경우 front = -1, rear = -1
#     6-3. 요소가 둘 이상인 경우 rear = (rear - 1 + k)%k 인덱스가 -1이 되면 k-1이 되도록 함



class MyCircularDeque:

    def __init__(self, k: int):
        self.arr = [0] * k
        self.k = k
        self.size = 0
        self.front = -1
        self.rear = 0

    def insertFront(self, value: int) -> bool:
        if self.isFull() : return False

        if self.size == 0 :
            self.front = 0
            self.rear = 0
        else :
            self.front = (self.front -1 + self.k) % self.k
        
        self.size += 1
        self.arr[self.front] = value
        return True
        

    def insertLast(self, value: int) -> bool:
        if self.isFull() : return False

        if self.size == 0 :
            self.front = 0
            self.rear = 0
        else :
            self.rear = (self.rear + 1) % self.k
        
        self.size += 1
        self.arr[self.rear] = value

        return True

    def deleteFront(self) -> bool:
        if self.isEmpty() : return False

        self.size -= 1
        self.front = (self.front + 1)%self.k
        return True
        

    def deleteLast(self) -> bool:
        if self.isEmpty() : return False

        self.size -= 1
        self.rear = (self.rear -1 +self.k)%self.k
        return True
        

    def getFront(self) -> int:
        if self.isEmpty() : return -1

        return self.arr[self.front]

    def getRear(self) -> int:
        if self.isEmpty() : return -1

        return self.arr[self.rear]

    def isEmpty(self) -> bool:
        return self.size == 0
        

    def isFull(self) -> bool:
        return self.size == self.k


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
'''
Exam Room
- n개의 좌석이 있고,
- 아무도 없을 때, 1번째부터 채우기
- 사람이 들어오면 가장 가까운 사람으로부터 가장 멀게 앉아야 함. : 0 -> n -> n//2
- 앉을 수 있는 자리가 여러 자리면, 가장 낮은 숫자부터 앉기.


ExamRoom(int n) 
- Initializes the object of the exam room with the number of the seats n.
int seat() 
- Returns the label of the seat at which the next student will set.
void leave(int p) 
- Indicates that the student sitting at seat p will leave the room. 
- It is guaranteed that there will be a student sitting at seat p.

'''


import heapq



class ExamRoom:

    def __init__(self, n: int):
        self.n = n # 좌석 개수
        self.heap = []

        self.heap.append((-self.valid_distance(0, n-1), 0, self.n-1)) # 초기화 : 전체 구간
        

    def valid_distance(self, start, end):
        '''
        선택된 구간의 "유효한(해당 구간에서 앉을 수 있는, 즉 최대 거리를 보장하는)" 거리
        '''
        # 한쪽이 빈 경우
        if start == 0 or end == self.n-1: # 초기 상태 밖에 없음
            return end- start
        
        return (end- start)//2 # 중앙까지의 거리
        

    def seat(self) -> int:
        pos =0
        dist, start, end = heapq.heappop(self.heap)
        dist = -dist

        if start == 0:
            pos = 0
        elif end == self.n-1: # tip (0,9)이어도 이 조건문은 걸리지 않음. elif라서
            pos = self.n-1
        else:
            pos = start + dist # 중앙자리
        
        if pos > start:
            heapq.heappush(self.heap, (-self.valid_distance(start, pos-1), start, pos-1))
        if pos < end:
            heapq.heappush(self.heap, (-self.valid_distance(pos+1, end), pos+1, end))


        return pos

    def leave(self, p: int) -> None:
        '''
        - 힙에서 떠난 좌석에 연결된 두 구간을 찾아 병합
        - 병합된 구간을 다시 힙에 삽입

        해당 좌석을 기준으로 왼쪽이 end, 오른쪽이 start인 구간들 병합
        '''
  
        left = right = None # 구간들

        for seat in self.heap:
            temp_start = seat[1]
            temp_end = seat[2]

            if (temp_start -1) == p:
                right = seat

            if (temp_end +1) == p:
                left = seat


        #p에 앉아있었다고 무조건 보장이다. (사이 자리를 제거하는 경우는 없음.)
        new_start, new_end = p, p

        if left:
            new_start = left[1]
            self.heap.remove(left)


        if right : 
            new_end = right[2]
            self.heap.remove(right)

        #병합.
        heapq.heappush(self.heap, (-self.valid_distance(new_start, new_end), new_start, new_end))



# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)


def main():
    commands = ["ExamRoom", "seat", "seat", "seat", "seat", "leave", "leave", "seat"]
    arguments = [[4], [], [], [], [], [1], [3], []]
    
    result = []
    room = None
    
    for i, command in enumerate(commands):
        if command == "ExamRoom":
            room = ExamRoom(arguments[i][0])  # Initialize the ExamRoom
            result.append(None)
        elif command == "seat":
            seat_number = room.seat()  # Call the seat function
            print(room.heap)
            result.append(seat_number)
        elif command == "leave":
            room.leave(arguments[i][0])  # Call the leave function
            print(room.heap)
            result.append(None)
        
        
    
    print(result)

if __name__ == "__main__":
    main()

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

import bisect
##binary ssearch를 활용해서 검색 혹은 삽입
'''
bisect.bisect(a, x, lo=0, hi= len(a)) : a에 x 값이 들어갈 자리의 인덱스 값을 반환
bisect.bisesct_right(a, x) : x와 동일한 값이 존재하면 해당 값의 뒷 인덱스 값을 반환
bisect.bisect_left(a, x) : x와 동일한 값의 인덱스 반환
bisect.insort(a, x) : 정렬된 시퀀스 a에 x값을 삽입
'''


class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.students = [] # 현재 앉아 있는 좌석 정보
        

    def seat(self) -> int:
        '''
        가장 가까운 사람과 가장 멀어지기
        '''
        if not self.students :  # 빈 것이라면 맨 처음
            student  = 0
        
        else:
            #초기값 : 그냥 처음엔 혼자 앉아있으니까.
            max_dist = self.students[0]
            student = 0


            
            for i in range(1, len(self.students)): 
                # 앉은 자리 사이사이 공간 넓이를 체크 -> 가장 넓은 공간의 중앙에 앉아버리기

                prev = self.students[i -1]
                curr = self.students[i]

                dist = (curr- prev) // 2
                
                if dist > max_dist: # 가장 넓은지 체크
                    max_dist = dist #여기다!
                    student = prev + dist # 에잇 앉아버려!
    
            #마지막 칸에 앉는 경우도 생각하기
            if (self.n-1) -(self.students[-1])> max_dist :
                student = self.n-1
        
        bisect.insort(self.students, student)
        return student
        '''
        위 코드의 이슈 : 결국 매번 들어올때마다 처음부터 검사해야 함.
        '''
        

    def leave(self, p: int) -> None:
        self.students.remove(p)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)
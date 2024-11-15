'''
Array, Binary Search, DP

Binary search 적용 tip
어떤 정렬된 "배열"에서 "어떤 것"을 찾는다.
1. "어떤 것"을 정의해야 한다.
2. 조건에 따라 찾는 범위를 줄여 나간다. : "조건" 정의 필요 (기존: 중간보다 크다 혹은 작다)
3. 처음에는 양쪽 끝에서 시작, 그리고 그 어떤 것은 찾는 범위 내에서 가장 중간에서 시작.
4. 조건에 따라 찾는 범위를 반으로 줄여 나간다.

time complexity : O(logN)


'''

from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        '''
        모든 열, 모든 행에서 binary searching을 하는 것보다, 해야 하는 범위를 먼저 줄인다. 
        '''

        diagonals = []
        m = len(matrix) # 행 
        n = len(matrix[0]) # 열
        diagonals = [(matrix[m-1-i][n-1-i], (m-1-i, n-1-i)) for i in range(min(m, n)-1, -1, -1)] #min(m, n)개 만큼
        
        dia_vals = [d[0] for d in diagonals]
        #diagonal에서 위치 찾기
        i, j = 0, 0
        s , e = 0, len(dia_vals)-1

        #O(log(min(m, n)))
        while(s <=e):
            m = (s+e) // 2
            if dia_vals[m] == target:
                return True
            elif dia_vals[m] < target:
                s = m+1
            else:
                e = m-1

        # 대각선 탐색 결과 검증
        if s == 0:  # 모든 대각선 값보다 작음
            i, j = diagonals[0][1]
        elif s == len(dia_vals):  # 모든 대각선 값보다 큼
            return False
        else:
            i, j = diagonals[s - 1][1]  


        r1 = self.binary_search(matrix[i][:j+1], target)  #O(log(j))
        r2 = self.binary_search([m[j] for m in matrix[:i+1]], target) #O(log(i))

        return (r1 == target) or (r2 == target)




    def binary_search(self, L : list, v) -> int:
        start, end = 0, len(L)-1

        while(start <= end):
            mid = (start + end) // 2

            if L[mid] == v:
                return mid
            
            elif L[mid] < v:
                start = mid +1
            else:
                end = mid -1

        return -1



def main():

    sol = Solution()

    matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]
    target = 20
    
    ans = sol.searchMatrix(matrix, target) 
    print(ans) #False


    m = [[-5]]
    t = -2 
    print(sol.searchMatrix(m, t)) # False

    m2 = [[-1,3]]
    t2= -1
    ans2 = sol.searchMatrix(m2, t2)
    print(ans2) # True


    m3 = [[5], [6]]
    t3 = 5
    ans3 = sol.searchMatrix(m3, t3)
    print(ans3)  # Expected: True



if __name__ == "__main__":
    main()
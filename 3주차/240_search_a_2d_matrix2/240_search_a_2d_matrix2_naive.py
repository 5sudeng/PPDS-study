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
        모든 열 혹은 행에 대해 binary searching을 하는 것.
        '''
        
        m = len(matrix) # 행 
 
        for i in range(m):
            if self.binary_search(matrix[i], target):
                return True

        return False


    def binary_search(self, L : list, v) -> int:
        start, end = 0, len(L)-1

        while(start <= end):
            mid = (start + end) // 2

            if L[mid] == v:
                return True
            
            elif L[mid] < v:
                start = mid +1
            else:
                end = mid -1

        return False



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
    print(ans3)  # True



if __name__ == "__main__":
    main()
'''
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.


접근 방식 : priority queue or sorting
'''

from typing import List
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        

        '''
        python의 sorting : Timsort
        : Merge sort와 insert sort의 하이브리드
        최선 : O(N) / 평균 혹은 최악 : O(nlogn)
        '''
        ans = sorted([(i, sum(a)) for i, a in enumerate(mat)],key = lambda x : x[1])[:k]
        
        return [x[0] for x in ans]
    

if __name__ == "__main__":
    mat = [[1,1,0,0,0],
            [1,1,1,1,0],
            [1,0,0,0,0],
            [1,1,0,0,0],
            [1,1,1,1,1]]
    
    k = 3

    sol = Solution()
    print(sol.kWeakestRows(mat, k))
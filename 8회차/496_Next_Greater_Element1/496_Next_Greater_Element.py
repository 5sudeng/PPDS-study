from typing import List

class Solution:
    def naive_nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer = []
        for target in nums1:
            # nums2에서 target의 인덱스 찾기
            try:
                j = nums2.index(target)
            except ValueError:
                answer.append(-1)
                continue
            
            # nums2[j+1:]에서 target보다 큰 첫 번째 값 찾기
            next_greater = -1
            for index in range(j + 1, len(nums2)):
                if nums2[index] > nums2[j]:
                    next_greater = nums2[index]
                    break
            
            answer.append(next_greater)
        return answer
from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        next_greater = {}
        stack = []
        
        # nums2를 역순으로 탐색하며 next greater map 작성
        for num in reversed(nums2):
            while stack and stack[-1] <= num:
                stack.pop()
            if stack:
                next_greater[num] = stack[-1]
            else:
                next_greater[num] = -1
            stack.append(num)
        
        # nums1에 대해 next greater 값 찾기
        answer = [next_greater[num] for num in nums1]
        return answer

from typing import List

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ans = []  # 결과 리스트

        for curr in asteroids:
            while ans and curr < 0 < ans[-1]:  # 충돌 조건: curr이 음수이고 ans의 마지막 요소가 양수
                if abs(ans[-1]) < abs(curr):  # ans의 마지막 요소가 더 작으면 제거
                    ans.pop()
                    continue
                elif abs(ans[-1]) == abs(curr):  # 크기가 같으면 둘 다 제거
                    ans.pop()
                break  # curr이 파괴됨
            else:
                ans.append(curr)  # 충돌하지 않는 경우 추가

        return ans

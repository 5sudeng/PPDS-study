
from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        

        # dp[i] 정의 : i 번째 집을 검사 했을 때, (털지 안털지), 지금까지 얻은 최대 값.

        dp = [0]*len(nums)

        if len(nums) == 1:
            return nums[0]
        
        #초기값 : 
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1]) ## 이게 중요.

        for i in range(2, len(nums)):
        
            # 한칸을 뛰고, 이번 집을 털지. 아님 이번 집은 넘기고, 이전 집에서 구한 최대 상태를 유지할 지.
            dp[i] = max(dp[i-2] + nums[i], dp[i-1])
        
        return dp[-1]
    

def main():
    houses = [1,2,3,1] # [2,7,9,3,1] # [2,1,1,2]
    sol = Solution()
    print(sol.rob(houses))

if __name__ == "__main__":
    main()
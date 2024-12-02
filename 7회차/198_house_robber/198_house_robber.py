class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:  # 빈 입력 처리
            return 0
        if len(nums) == 1:  # 집이 하나일 경우
            return nums[0]

        dp = nums[:]
        dp[1] = max(nums[0], nums[1])  # 두 번째 집까지 고려

        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])  # 이전 최대와 현재 집을 포함한 최대 비교

        return dp[-1]  # 마지막 값 반환
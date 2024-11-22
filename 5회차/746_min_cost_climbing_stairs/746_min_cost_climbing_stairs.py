# cost = [10, 15, 20, 25, 30] 이라고 해보자.

# index = 0, 1은 각각 본인 그대로의 cost가 최소일 것이므로 i = 2 부터 for 문 시작

# cost[i]에 대해 그 전에서 왔을 수도 있고, 그 전전에서 왔을 수도 있으므로 어떤 경로로 오는 것이 cost를 더 적게 하는지 비교한다.

# cost[i-2]가 cost[i-1]보다 작다면 cost[i-2] 값을 cost[i]에 더한다.

# ⇒ `i = 0 or 1` [10, 15, 20, 25, 30]

# ⇒ `i=2`        [10, 15, 30, 25, 30]  (10에서 오는 것이 더 적은 cost)

# ⇒ `i=3`        [10, 15, 30, 40, 30] 

# ⇒ `i=4`        [10, 15, 30, 40, 60]

# 그러면 맨 마지막 혹은 마지막 바로 직전에 도달하면 그 다음에 바로 top을 갈 수 있으니까 그 둘을 비교해서 더 적은 값을 return한다.

# min(cost[n-2], cost[n-1])

# ⇒ 위의 예시에서는 40

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = cost

        for i in range(2, len(cost)):
            if dp[i-2] + dp[i] < dp[i-1] + dp[i]:
                dp[i] = dp[i-2] + dp[i]
            else :
                dp[i] = dp[i-1] + dp[i]
            

        if dp[-1] < dp[-2]:
            return dp[-1]
        else :
            return dp[-2]

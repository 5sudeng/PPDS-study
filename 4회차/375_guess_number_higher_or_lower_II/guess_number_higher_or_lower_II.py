class Solution:
    def __init__(self) :
        self.dp = [[0] * 201 for _ in range(201)]

    def calculate(self, start, end, n) :

        if (start == end) :
            return 0
        if (self.dp[start][end]) :
            return self.dp[start][end]

        ans = float('inf')

        for i in range(start, end+1) :
            # i로 예측한다고 가정!
            c1 = 0; c2 = 0; c3 = 0 #case 1,2,3
            c1 = 0; #case 1: i가 정답일 때 - 사실 없어도 될 듯
            if (i > 1) : #1로 예측한 경우.. 더 작은 경우의 계산이 필요없기 때문
                c2 = i + self.calculate(start, i-1, n)
            if (i < n) : #n으로 예측할 경우 더 큰 경우의 계산이 필요없기 때문
                c3 = i + self.calculate(i+1, end, n)
            ans = min(ans, max(c1, c2, c3))

        self.dp[start][end] = ans
        return ans

    def getMoneyAmount(self, n: int) -> int:
        return self.calculate(1, n, n)
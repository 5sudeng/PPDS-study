class Solution(object):
    def maximalSquare(self, matrix):
        m = len(matrix)
        n = len(matrix[0])

        dp = [[0]*n for _ in range(m)]
        largest = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '0':
                    dp[i][j] = 0
                else:
                    if i==0 or j==0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1
                largest = max(largest, dp[i][j])
        return largest*largest
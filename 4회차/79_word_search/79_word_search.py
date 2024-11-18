class Solution:
    def backtrack(self, board, visited, row, col, word, idx):
        m, n = len(board), len(board[0])

        # found
        if idx == len(word):
            return True

        # boundary check
        if row < 0 or row >= m or col < 0 or col >= n:
            return False
        # invalid path
        if visited[row][col] or board[row][col] != word[idx]:
            return False

        # find valid path from board[row][col]
        visited[row][col] = True
        res = (self.backtrack(board, visited, row + 1, col, word, idx + 1) or  # down
               self.backtrack(board, visited, row - 1, col, word, idx + 1) or  # up
               self.backtrack(board, visited, row, col + 1, word, idx + 1) or  # right
               self.backtrack(board, visited, row, col - 1, word, idx + 1))    # left
        visited[row][col] = False
        return res

    def exist(self, board, word):
        m, n = len(board), len(board[0])
        visited = [[False] * n for _ in range(m)]

        for row in range(m):
            for col in range(n):
                if board[row][col] == word[0]:
                    if self.backtrack(board, visited, row, col, word, 0):
                        return True
        return False
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        m = len(board)
        n = len(board[0])
        visited = [[False] * n for _ in range(m)]  # 방문 여부 기록
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]  # 상하좌우 방향
        count = 0

        def dfs(y, x):
            # 현재 위치를 방문 처리
            visited[y][x] = True
            # 4방향 탐색
            for dy, dx in directions:
                ny, nx = y + dy, x + dx
                # 범위를 벗어나거나 이미 방문했거나, 'X'가 아니라면 무시
                if 0 <= ny < m and 0 <= nx < n and not visited[ny][nx] and board[ny][nx] == 'X':
                    dfs(ny, nx)

        # 모든 격자를 순회
        for y in range(m):
            for x in range(n):
                # 아직 방문하지 않은 전투함의 시작점 발견 시 DFS 시작
                if board[y][x] == 'X' and not visited[y][x]:
                    count += 1
                    dfs(y, x)

        return count
    def countBattleships2(self, board: List[List[str]]) -> int:
        # number of islands: bfs
        ans = 0               
        m = len(board)       
        n = len(board[0]) 
        if(len(board)==0): return 0;           
 
        # 
        # 모든 칸을 확인해서 시작점으로 잡아야함        
        for y in range(m):            
            for x in range(n):            	
                if board[y][x]=='X':
                    if (y>0 and board[y-1][x]=='X') or (x>0 and board[y][x-1]=='X'):
                        continue
                ans+=1    
        return ans
# Main function
if __name__ == "__main__":
    # 입력 보드 설정
    board = [
        ["X", ".", ".", "X"],
        [".", ".", ".", "X"],
        [".", ".", ".", "X"]
    ]

    # Solution 클래스 객체 생성
    sol = Solution()

    # 첫 번째 방식 (DFS) 호출
    result_dfs = sol.countBattleships(board)
    print("DFS를 사용한 결과:", result_dfs)

    # 두 번째 방식 (BFS / 간단한 탐색) 호출
    result_simple = sol.countBattleships2(board)
    print("간단한 탐색을 사용한 결과:", result_simple)
        
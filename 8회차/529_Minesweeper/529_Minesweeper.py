class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        rows, cols = len(board), len(board[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]
    
        def count_adjacent_mines(r, c):
            # Count the number of mines adjacent to (r, c)
            count = 0
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == 'M':
                    count += 1
            return count
        
        def dfs(r, c):
            # If the cell is already revealed or out of bounds, do nothing
            if not (0 <= r < rows and 0 <= c < cols) or board[r][c] != 'E':
                return
            
            # Count adjacent mines
            mine_count = count_adjacent_mines(r, c)
            if mine_count > 0:
                # If there are adjacent mines, reveal the number and stop
                board[r][c] = str(mine_count)
            else:
                # If no adjacent mines, reveal as 'B' and recursively reveal neighbors
                board[r][c] = 'B'
                for dr, dc in directions:
                    dfs(r + dr, c + dc)

        # Start processing the click
        click_r, click_c = click
        if board[click_r][click_c] == 'M':
            # If a mine is clicked, game over
            board[click_r][click_c] = 'X'
        else:
            # Start DFS from the clicked cell
            dfs(click_r, click_c)
        
        return board
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    int countAdjacentMines(vector<vector<char>>& board, int r, int c) {
        int count = 0;
        int rows = board.size();
        int cols = board[0].size();
        for (const auto& dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'M') {
                count++;
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'E') {
            return;
        }
        
        int mineCount = countAdjacentMines(board, r, c);
        if (mineCount > 0) {
            board[r][c] = mineCount + '0';
        } else {
            board[r][c] = 'B';
            for (const auto& dir : directions) {
                dfs(board, r + dir.first, c + dir.second);
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int click_r = click[0];
        int click_c = click[1];
        
        if (board[click_r][click_c] == 'M') {
            board[click_r][click_c] = 'X';
        } else {
            dfs(board, click_r, click_c);
        }
        
        return board;
    }
};

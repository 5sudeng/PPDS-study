#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string word, int idx) {
        int m = board.size();
        int n = board[0].size();

        // found
        if (idx == word.size()) { return true; }

        // boundary check
        if (row<0 || row>=m || col<0 || col>=n) { return false; }
        // invalid path
        if (visited[row][col] || board[row][col] != word[idx]) { return false; }

        // find valid path from board[row][col]
        visited[row][col] = true;
        bool res = (backtrack(board, visited, row+1, col, word, idx+1) || // up
                    backtrack(board, visited, row-1, col, word, idx+1) || // down
                    backtrack(board, visited, row, col+1, word, idx+1) || // right
                    backtrack(board, visited, row, col-1, word, idx+1));  // left
        visited[row][col] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int row=0; row<m; ++row) {
            for (int col=0; col<n; ++col) {
                if (board[row][col] == word[0]) {
                    if (backtrack(board, visited, row, col, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/*
without vector<vector<bool>> visited (faster!)

class Solution {
public:
    bool backtrack(vector<vector<char>>& board, int row, int col, string word, int idx) {
        int m = board.size();
        int n = board[0].size();

        // found 
        if (idx == word.size()) { return true; }
        
        // boundary check
        if (row<0 || row>=m || col<0 || col>=n) { return false; }
        // invalid path
        if (board[row][col] != word[idx]) { return false; }

        // find valid path from board[row][col]
        char ch = board[row][col];
        board[row][col] = '#';        
        bool res = (backtrack(board, row+1, col, word, idx+1) || // up
                    backtrack(board, row-1, col, word, idx+1) || // down
                    backtrack(board, row, col+1, word, idx+1) || // right
                    backtrack(board, row, col-1, word, idx+1));  // left
        board[row][col] = ch;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
                
        for (int row=0; row<m; ++row) {
            for (int col=0; col<n; ++col) {
                if (board[row][col] == word[0]) {
                    if (backtrack(board, row, col, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

*/
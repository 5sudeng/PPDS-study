#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_M 100
#define MAX_N 100

bool backtrack(char board[MAX_M][MAX_N], bool visited[MAX_M][MAX_N], int m, int n, int row, int col, char* word, int idx) {
    
    // found
    if (word[idx] == '\0') { return true; }

    // boundary check
    if (row < 0 || row >= m || col < 0 || col >= n) { return false; }
    // invalid path
    if (visited[row][col] || board[row][col] != word[idx]) { return false; }

    // find valid path from board[row][col]
    visited[row][col] = true;
    bool res = (backtrack(board, visited, m, n, row + 1, col, word, idx + 1) || // down
                backtrack(board, visited, m, n, row - 1, col, word, idx + 1) || // up
                backtrack(board, visited, m, n, row, col + 1, word, idx + 1) || // right
                backtrack(board, visited, m, n, row, col - 1, word, idx + 1));  // left
    visited[row][col] = false;
    return res;
}

bool exist(char board[MAX_M][MAX_N], int m, int n, char* word) {
    bool visited[MAX_M][MAX_N] = {false};

    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (board[row][col] == word[0]) {
                if (backtrack(board, visited, m, n, row, col, word, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}
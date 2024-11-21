#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if (b > a && c > a) { return a; } 
    else if (c > b) { return b; }
    else { return c; }
}

// C에서는 .size() 이런게 없으니까 m, n이 input으로 들어와줘야 함
int maximalSquare(char** matrix, int m, int n) {
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) { dp[i] = (int*)malloc(n * sizeof(int)); }

    int largest = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                if (i == 0 || j == 0) { 
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
            }
            if (dp[i][j] > largest) { largest = dp[i][j]; }
        }
    }

    // 메모리 해제
    for (int i = 0; i < m; i++) { free(dp[i]); }
    free(dp);

    return largest * largest; 
}
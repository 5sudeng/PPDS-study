#include <stdio.h>
#include <limits.h> // for INT_MIN

#define max(a, b) ((a) > (b) ? (a) : (b))

int solution(int A[], int N) {
    int dp[N];
    for (int i = 0; i < N; ++i) {
        dp[i] = INT_MIN;
    }
    dp[0] = A[0];

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] = max(dp[i], dp[i - j] + A[i]);
            }
        }
    }
    return dp[N - 1];
}

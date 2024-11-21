#include <limits.h> // LLONG_MAX를 사용하기 위해 추가

int dp[201][201]; // DP 배열 선언

long long calculate(int start, int end, int n) {
    if (start > end) {
        return 0; // 잘못된 호출에 대해 안전한 반환
    }
    if (start == end) {
        return 0; // 범위가 하나의 숫자인 경우 비용 없음
    }

    if (dp[start][end]) {
        return dp[start][end]; // 이미 계산된 값이 있으면 반환
    }

    long long ans = LLONG_MAX; // 초기값: 무한대

    for (int i = start; i <= end; i++) {
        long long c2 = 0, c3 = 0;

        // Case 2: 답이 i보다 작은 경우
        if (i > 1) {
            c2 = (long long)i + calculate(start, i - 1, n);
        }

        // Case 3: 답이 i보다 큰 경우
        if (i < n) {
            c3 = (long long)i + calculate(i + 1, end, n);
        }

        // 최악의 경우를 고려한 최소값 계산
        long long worst_case = c2 > c3 ? c2 : c3; // max(c2, c3)
        if (worst_case < ans) {
            ans = worst_case; // min(ans, worst_case)
        }
    }

    dp[start][end] = (int)ans; // 결과를 int로 저장 (값이 안전한 경우)
    return ans;
}

int getMoneyAmount(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0; // DP 배열 초기화
        }
    }

    return (int)calculate(1, n, n);
}
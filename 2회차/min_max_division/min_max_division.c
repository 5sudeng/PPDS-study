#include <stdio.h>
#include <limits.h>

int max(int arr[], int n) {
    int sol = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > sol) {
            sol = arr[i];
        }
    }
    return sol;
}

int sum(int arr[], int n) {
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += arr[i];
    }
    return sol;
}

int solution(int K, int M, int A[], int N) {
    int low = max(A, N);
    int high = sum(A, N);

    while (low != high) {
        int mid = (low + high) / 2;
        int cnt = 1;
        int tmp = 0;

        for (int i = 0; i < N; ++i) {
            if (tmp + A[i] > mid) {
                cnt += 1; tmp = A[i];
            } else {
                tmp += A[i];
            }
        }

        if (cnt > K) { low = mid + 1; } 
        else { high = mid; }
    }

    return low;
}

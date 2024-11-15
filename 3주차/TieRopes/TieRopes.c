#include <stdio.h>

int solution(int K, int A[], int N) {
    int count = 0;            // Number of ropes with length >= K
    int current_length = 0;   // Length of the current rope being formed

    for (int i = 0; i < N; ++i) {
        current_length += A[i];   // Tie the current rope with the next one
        if (current_length >= K) {
            count++;              // Found a rope of sufficient length
            current_length = 0;   // Reset to start forming a new rope
        }
    }

    return count;
}

// Example usage:
int main() {
    int K = 4;
    int A[] = {1, 2, 3, 4, 1, 1, 3};
    int N = sizeof(A) / sizeof(A[0]);
    int result = solution(K, A, N);
    printf("The maximum number of ropes of length >= %d is: %d\n", K, result);
    return 0;
}
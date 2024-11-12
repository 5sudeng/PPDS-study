#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int solution(int A[], int N) {
    qsort(A, N, sizeof(int), compare);

    int max_product_1 = A[N-1] * A[N-2] * A[N-3];
    int max_product_2 = A[0] * A[1] * A[N-1];

    if (A[0] >= 0) {
        return max_product_1;
    } else if (A[1] < 0) {
        return (max_product_1 > max_product_2) ? max_product_1 : max_product_2;
    } else {
        return max_product_1;
    }
}
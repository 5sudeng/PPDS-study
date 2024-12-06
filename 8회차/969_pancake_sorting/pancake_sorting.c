#include <stdlib.h>

void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    int* result = (int*)malloc(arrSize * 2 * sizeof(int)); // 결과 배열
    *returnSize = 0; // 반환 크기 초기화

    for (int currentSize = arrSize; currentSize > 1; --currentSize) {
        // 1. 현재 범위에서 최대값 찾기
        int maxIndex = 0;
        for (int i = 1; i < currentSize; ++i) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // 2. 최대값이 이미 제자리에 있으면 건너뜀
        if (maxIndex == currentSize - 1) continue;

        // 3. 최대값을 맨 앞으로 이동
        if (maxIndex != 0) {
            result[(*returnSize)++] = maxIndex + 1;
            reverse(arr, 0, maxIndex);
        }

        // 4. 최대값을 현재 범위의 끝으로 이동
        result[(*returnSize)++] = currentSize;
        reverse(arr, 0, currentSize - 1);
    }

    return result;
}
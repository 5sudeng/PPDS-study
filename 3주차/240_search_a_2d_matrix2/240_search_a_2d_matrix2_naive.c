#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 이진 탐색 함수
bool binary_search(int* arr, int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

// 행렬에서 target 찾기
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    for (int i = 0; i < matrixSize; i++) {
        if (binary_search(matrix[i], matrixColSize[i], target)) {
            return true;
        }
    }
    return false;
}

int main() {
    // 행렬 동적 할당
    int rows = 5;
    int cols = 5;

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // 행렬 초기화
    int data[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = data[i][j];
        }
    }

    // 각 행의 열 크기 저장
    int matrixColSize[5] = {5, 5, 5, 5, 5};

    // 타겟 값
    int target = 9;

    // 행렬에서 타겟 찾기
    if (searchMatrix(matrix, rows, matrixColSize, target)) {
        printf("Target %d found in matrix.\n", target);
    } else {
        printf("Target %d not found in matrix.\n", target);
    }

    // 메모리 해제
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

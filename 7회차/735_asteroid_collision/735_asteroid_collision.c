#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));  // 결과 스택
    int stackSize = 0;

    for (int i = 0; i < asteroidsSize; i++) {
        int curr = asteroids[i];
        int crashed = 0;

        while (stackSize > 0 && curr < 0 && stack[stackSize - 1] > 0) {  // 충돌 조건
            int top = stack[stackSize - 1];

            if (abs(top) < abs(curr)) {  // 스택의 마지막 요소가 더 작으면 제거
                stackSize--;
            } else if (abs(top) == abs(curr)) {  // 크기가 같으면 둘 다 제거
                stackSize--;
                crashed = 1;
                break;
            } else {  // 스택의 마지막 요소가 더 크면 curr이 파괴됨
                crashed = 1;
                break;
            }
        }

        if (!crashed) {  // 충돌하지 않는 경우 스택에 추가
            stack[stackSize++] = curr;
        }
    }

    *returnSize = stackSize;
    return stack;  // 결과 스택 반환
}

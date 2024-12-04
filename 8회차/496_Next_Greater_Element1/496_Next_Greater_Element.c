#include <stdio.h>
#include <stdlib.h>

int* naive_nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* answer = (int*)malloc(sizeof(int) * nums1Size);
    
    for (int i = 0; i < nums1Size; i++) {
        int target = nums1[i];
        int j, next_greater = -1;

        // nums2에서 target의 인덱스 찾기
        for (j = 0; j < nums2Size; j++) {
            if (nums2[j] == target) break;
        }

        // nums2[j+1:]에서 target보다 큰 첫 번째 값 찾기
        for (int k = j + 1; k < nums2Size; k++) {
            if (nums2[k] > target) {
                next_greater = nums2[k];
                break;
            }
        }

        answer[i] = next_greater;
    }
    return answer;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
} Stack;

void stack_init(Stack* stack, int size) {
    stack->data = (int*)malloc(sizeof(int) * size);
    stack->top = -1;
}

void stack_push(Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

int stack_pop(Stack* stack) {
    return stack->data[stack->top--];
}

int stack_peek(Stack* stack) {
    return stack->data[stack->top];
}

int stack_is_empty(Stack* stack) {
    return stack->top == -1;
}

void stack_free(Stack* stack) {
    free(stack->data);
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* answer = (int*)malloc(sizeof(int) * nums1Size);
    int* next_greater = (int*)malloc(sizeof(int) * nums2Size);
    int map[10000] = {0}; // Assuming all numbers are in the range [0, 9999]

    Stack stack;
    stack_init(&stack, nums2Size);

    // nums2를 역순으로 순회하며 next greater 값을 찾기
    for (int i = nums2Size - 1; i >= 0; i--) {
        while (!stack_is_empty(&stack) && stack_peek(&stack) <= nums2[i]) {
            stack_pop(&stack);
        }

        if (!stack_is_empty(&stack)) {
            next_greater[i] = stack_peek(&stack);
        } else {
            next_greater[i] = -1;
        }

        stack_push(&stack, nums2[i]);
        map[nums2[i]] = next_greater[i]; // nums2 값과 매핑
    }

    stack_free(&stack);

    // nums1에 대해 next greater 값 매핑
    for (int i = 0; i < nums1Size; i++) {
        answer[i] = map[nums1[i]];
    }

    free(next_greater);
    return answer;
}

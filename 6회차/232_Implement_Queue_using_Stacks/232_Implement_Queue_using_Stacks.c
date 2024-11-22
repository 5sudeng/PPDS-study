#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue 구조체 정의
typedef struct {
    int *main_stack;
    int *sub_stack;
    int main_top;  // main_stack의 현재 위치 (인덱스)
    int sub_top;   // sub_stack의 현재 위치 (인덱스)
    int capacity;  // 스택의 최대 크기
} MyQueue;

// MyQueue 생성자
MyQueue* myQueueCreate(int capacity) {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->main_stack = (int*)malloc(sizeof(int) * capacity);
    queue->sub_stack = (int*)malloc(sizeof(int) * capacity);
    queue->main_top = -1;  // main_stack이 비어 있음
    queue->sub_top = -1;   // sub_stack이 비어 있음
    queue->capacity = capacity;
    return queue;
}

// Push 연산
void myQueuePush(MyQueue* queue, int x) {
    if (queue->main_top + 1 >= queue->capacity) {
        printf("Queue overflow\n");
        return;
    }
    queue->main_stack[++queue->main_top] = x;
}

// Pop 연산
int myQueuePop(MyQueue* queue) {
    if (queue->sub_top == -1) {  // sub_stack이 비어 있을 경우 main_stack에서 옮김
        while (queue->main_top != -1) {
            queue->sub_stack[++queue->sub_top] = queue->main_stack[queue->main_top--];
        }
    }
    if (queue->sub_top == -1) {  // sub_stack이 여전히 비어 있으면 큐가 비어 있음
        printf("Queue is empty\n");
        return -1;
    }
    return queue->sub_stack[queue->sub_top--];
}

// Peek 연산
int myQueuePeek(MyQueue* queue) {
    if (queue->sub_top == -1) {  // sub_stack이 비어 있을 경우 main_stack에서 옮김
        while (queue->main_top != -1) {
            queue->sub_stack[++queue->sub_top] = queue->main_stack[queue->main_top--];
        }
    }
    if (queue->sub_top == -1) {  // sub_stack이 여전히 비어 있으면 큐가 비어 있음
        printf("Queue is empty\n");
        return -1;
    }
    return queue->sub_stack[queue->sub_top];
}

// Empty 연산
bool myQueueEmpty(MyQueue* queue) {
    return queue->main_top == -1 && queue->sub_top == -1;
}

// MyQueue 소멸자
void myQueueFree(MyQueue* queue) {
    free(queue->main_stack);
    free(queue->sub_stack);
    free(queue);
}

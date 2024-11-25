#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int *queue1, *queue2;   
    int size1, size2;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->capacity = 100;
    obj->queue1 = (int*)malloc(obj->capacity * sizeof(int));
    obj->queue2 = (int*)malloc(obj->capacity * sizeof(int));
    obj->size1 = 0;
    obj->size2 = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[obj->size1++] = x;
}

int myStackPop(MyStack* obj) {
    if (obj->size1 == 0) return -1;
    int back = obj->queue1[obj->size1 - 1];

    for (int i = 0; i < obj->size1 - 1; ++i) {
        obj->queue2[obj->size2++] = obj->queue1[i];
    }

    obj->size1 = obj->size2; 
    obj->size2 = 0;

    int *temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
    obj->size2 = 0;

    return back;
}

int myStackTop(MyStack* obj) {
    if (obj->size1 == 0) return -1;
    return obj->queue1[obj->size1 - 1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size1 == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}



/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
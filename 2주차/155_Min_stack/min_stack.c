#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *val_stack;
    int *min_stack;
    int top_index;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->capacity = 100; // Initial capacity
    stack->val_stack = (int*)malloc(stack->capacity * sizeof(int));
    stack->min_stack = (int*)malloc(stack->capacity * sizeof(int));
    stack->top_index = -1;
    return stack;
}

void resizeStack(MinStack* stack) {
    stack->capacity *= 2;
    stack->val_stack = (int*)realloc(stack->val_stack, stack->capacity * sizeof(int));
    stack->min_stack = (int*)realloc(stack->min_stack, stack->capacity * sizeof(int));
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top_index + 1 >= obj->capacity) {
        resizeStack(obj);
    }
    obj->val_stack[++obj->top_index] = val;
    if (obj->top_index == 0) {
        obj->min_stack[obj->top_index] = val;
    } else {
        obj->min_stack[obj->top_index] = (obj->min_stack[obj->top_index - 1] < val) 
                                         ? obj->min_stack[obj->top_index - 1] : val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top_index >= 0) {
        obj->top_index--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top_index >= 0) {
        return obj->val_stack[obj->top_index];
    }
    return INT_MIN; // Return a default value for empty stack
}

int minStackGetMin(MinStack* obj) {
    if (obj->top_index >= 0) {
        return obj->min_stack[obj->top_index];
    }
    return INT_MIN; // Return a default value for empty stack
}

void minStackFree(MinStack* obj) {
    free(obj->val_stack);
    free(obj->min_stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

/* CircularDeque
1. 초기화 : 크기 k의 빈 배열 arr 생성, front = -1, rear = 0
2. 첫번째 요소 삽입 : index 0에 값이 삽입되고, front = 0, rear = 0
3. insertFront : 
    3-1. deque가 Full인지 확인
    3-2. front == 0이면 front를 배열의 마지막 인덱스로 이동
    3-3. front != 0이면 front를 1만큼 감소시키고 arr[front] = value
4. insertLast :
    4-1. deque가 Full인지 확인
    4-2. rear == k-1이면 rear = 0으로 초기화
    4-3. rear != k-1이면 rear를  1만큼 증가시키고 arr[rear] = value
5. deleteFront : 
    5-1. deque가 Empty인지 확인
    5-2. 요소가 하나만 있는 경우 front = -1, rear = -1
    5-3. 요소가 둘 이상인 경우 front = (front + 1)%k 인덱스 배열 넘어서면 다시 0으로 돌아오도록 함
6. deleteLast : 
    6-1. deque가 Empty인지 확인
    6-2. 요소가 하나만 있는 경우 front = -1, rear = -1
    6-3. 요소가 둘 이상인 경우 rear = (rear - 1 + k)%k 인덱스가 -1이 되면 k-1이 되도록 함
*/


typedef struct {
    int* arr;
    int size;
    int count;
    int front;
    int rear;
} MyCircularDeque;

bool myCircularDequeIsFull(MyCircularDeque* obj);
bool myCircularDequeIsEmpty(MyCircularDeque* obj);

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* deq = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    deq->size = k;
    deq->count = 0;
    deq->front = 0;
    deq->rear = 0;
    deq->arr = (int*)malloc(k * sizeof(int));
    return deq;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->front --;
    obj->count ++;
    if (obj->front == -1){
        obj->front = obj->size - 1;
    }
    obj->arr[obj->front] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->arr[obj->rear] = value;
    obj->count ++;
    obj->rear = (obj->rear + 1) % obj->size;
    
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->front = (obj->front + 1)%obj->size;
    obj->count --;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->rear = (obj->rear - 1 + obj->size) % obj->size;
    obj->count --;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    int rearIndex = obj->rear - 1;
    if (rearIndex == -1){
        rearIndex = (rearIndex + obj->size)%obj->size;
    }
    return obj->arr[rearIndex];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->count == 0) return true;
    return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->count == obj->size) return true;
    return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
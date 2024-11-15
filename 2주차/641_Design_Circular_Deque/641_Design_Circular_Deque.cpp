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


class MyCircularDeque {
    int* arr;
    int size;
    int front;
    int rear;
    int k;

public:
    MyCircularDeque(int k) {
        // initialization
        arr = new int[k];
        front = -1;
        rear = 0;
        size = 0;
        this->k = k;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        // if first element 
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        // if not first element
        else {
            front = (front - 1 + k)%k; // -1이면 배열의 마지막으로 감
        }

        arr[front] = value;
        size++;

        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;

        // if first element 
        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        // if not first element
        else {
            rear = (rear + 1)%k;
        }
        arr[rear] = value;
        size ++;
        return true;
        
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;

        if (front == rear) { // 배열이 비었거나 요소가 하나일 때
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % k; // 배열의 끝보다 나가면 0으로 순환하도록
        }

        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        if (front == rear) { // 배열이 비었거나 요소가 하나일 때
            front = -1;
            rear = -1;
        } else {
            rear = (rear - 1 + k) % k;// -1이면 배열의 마지막으로 감
        }

        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
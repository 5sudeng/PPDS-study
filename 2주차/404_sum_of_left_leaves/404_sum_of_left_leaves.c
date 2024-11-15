/*
C에서는 Queue 구현이 없기 때문에, 
Queue Struct을 별도로 구현해야 한다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


TreeNode* createNode(int val){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode ->val = val;
    newNode ->left = NULL;
    newNode ->right = NULL;
    return newNode;
}

typedef struct QueueNode{
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}


// Queue에 원소 추가
void enqueue(Queue* q, TreeNode* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Queue에서 원소 제거 및 반환
TreeNode* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    TreeNode* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

// Queue가 비었는지 확인
int isEmpty(Queue* q) {
    return q->front == NULL;
}



int sumOfLeftLeaves(TreeNode* root) {
    if (root==NULL) return 0;

    int ans = 0;
    Queue* q  = createQueue();
    enqueue(q, root);


    while(!isEmpty(q)){
        TreeNode* curnode = dequeue(q);;

        if (curnode->left !=NULL){
            TreeNode* temp = curnode -> left;
            if (temp->left == NULL && temp->right == NULL){
                ans += temp->val;

            }
            else{
                enqueue(q, temp);
            }
        }

        if (curnode-> right !=NULL){
            enqueue(q, curnode->right);
        }
    }

    return ans;
}

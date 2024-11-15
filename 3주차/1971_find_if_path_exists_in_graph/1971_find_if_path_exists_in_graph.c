#include <stdio.h>

#define MAX_NODES 1000

int adjList[MAX_NODES][MAX_NODES]; // 인접 리스트 배열 (2차원 배열)
int adjSize[MAX_NODES]; // 각 노드의 인접 노드 개수를 저장

int queue[MAX_NODES]; // 큐 배열
int front = 0, rear = -1;

void enqueue(int value) { queue[++rear] = value; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front > rear; }

int validPath(int n, int edges[][2], int edgesSize, int source, int destination) {
    int visited[MAX_NODES] = { 0 }; // 방문 배열 초기화

    // 인접 리스트 생성
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
    }

    // BFS 초기화
    enqueue(source);
    visited[source] = 1;

    while (!isEmpty()) {
        int curr = dequeue();

        if (curr == destination) {
            return 1; // 경로가 존재함
        }

        for (int i = 0; i < adjSize[curr]; i++) {
            int neighbor = adjList[curr][i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
        }
    }

    return 0; // 경로가 존재하지 않음
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100

// 재귀 DFS 함수
bool DFS_check(int node, int current_group, int** graph, int* group_record, int* sizes) {
    group_record[node] = current_group;

    for (int i = 0; i < sizes[node]; i++) {
        int neighbor = graph[node][i];

        if (group_record[neighbor] == -1) {
            // 이웃 노드가 아직 방문되지 않았다면 반대 그룹으로 설정하고 재귀 호출
            if (!DFS_check(neighbor, 1 - current_group, graph, group_record, sizes)) {
                return false;
            }
        } else if (group_record[neighbor] == current_group) {
            // 이웃 노드가 같은 그룹에 있다면 Bipartite가 아님
            return false;
        }
    }
    return true;
}

// 전체 그래프가 Bipartite인지 확인
bool isBipartite(int** graph, int* sizes, int numNodes) {
    int group_record[MAX_NODES];
    memset(group_record, -1, sizeof(group_record)); // -1로 초기화 (방문하지 않음)

    for (int node = 0; node < numNodes; node++) {
        if (group_record[node] == -1) { // 아직 방문하지 않은 경우
            if (!DFS_check(node, 0, graph, group_record, sizes)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // 입력 그래프 (인접 리스트)
    int numNodes1 = 4;
    int sizes1[] = {2, 2, 2, 2};
    int* graph1[] = {
        (int[]){1, 3},
        (int[]){0, 2},
        (int[]){1, 3},
        (int[]){0, 2}
    };

    int numNodes2 = 4;
    int sizes2[] = {3, 2, 3, 2};
    int* graph2[] = {
        (int[]){1, 2, 3},
        (int[]){0, 2},
        (int[]){0, 1, 3},
        (int[]){0, 2}
    };

    if (isBipartite(graph1, sizes1, numNodes1)) {
        printf("Graph1 is Bipartite\n");
    } else {
        printf("Graph1 is not Bipartite\n");
    }

    if (isBipartite(graph2, sizes2, numNodes2)) {
        printf("Graph2 is Bipartite\n");
    } else {
        printf("Graph2 is not Bipartite\n");
    }

    return 0;
}

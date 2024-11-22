#include <vector>
#include <queue>
using namespace std;

class Solution {
public: //모든 point를 잇는 minimum distance를 구하는 문제. 
        //Minimum spanning tree로 푼다! prim's 또는 kruskal's로 풀면 됨.

    int minCostConnectPoints(vector<vector<int>>& points) {
        //prim's 풀이. (greedy, O(ElogV))
        //현재 MST에 가장 가까운 노드를 가장 낮은 비용으로 추가하는 방식 (greedy)
        /*
        임의의 노드에서 시작.
        -> 해당 노드와 연결된 모든 edge 중 비용이 가장 낮은 것과 연결된 node MST에 추가
        -> 추가된 edge와 연결된 모든 edge 탐색
        */

        int num = points.size(); //총 point 개수
        int distance = 0; //최종 결과로 반환 될 최소 거리의 합
        int count =0; //MST에 포함된 노드 수

        vector<bool> marked(num, 0); //각 점이 MST에 포함되었는지 추적

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        PQ.push({0, 0});//0번 노드로 시작
        
        while(count < num){ //모든 노드가 연결될 때 까지 (모든 노드가 MST에 포함 될 때 까지) 반복
            //get min
            int cost = PQ.top().first; //현재 선택한 간선의 비용
            int i = PQ.top().second; //현재 선택한 노드
            PQ.pop();
            
            if (marked[i]){
                continue; //이미 MST에 포함된 노드는 건너 뜀
            }

            marked[i] = true; //현재 노드 MST에 추가
            distance += cost; //선택한 간선의 비용 총 거리 합에 더하기
            ++count; //MST에 포함된 노드 수 증가
            
            //연결 안 된 노드 처리
            for (int k = 0; k < num; ++k){ //모든 노드에 대해 반복
                if (!marked[k]){ //아직 MST에 포함되지 않은 노드만 처리
                    int d = (abs(points[i][0] - points[k][0]) + abs(points[i][1] - points[k][1]));
                    PQ.push({d,k}); //현재노드와의 거리 계산 후 큐에 추가
                }
            }
        }
        
        return distance;
    }
};
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> neighbor(n);
        for (auto edge : edges) {
            neighbor[edge[0]].push_back(edge[1]);
            neighbor[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0); // 0: not visited, 1: visited
        queue<int> q; q.push(source);

        while (!q.empty()) {
            int curr = q.front(); q.pop();

            if (curr == destination) {
                return true;
            }

            if (visited[curr] == 0) {
                visited[curr] = 1;
                for (auto x : neighbor[curr]) {
                    q.push(x);
                }
            }
            
        }
        return false;
    }
};
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;




class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> group;

        int nums = graph.size();

        for(int node = 0; node<nums; node++){
            if (group.find(node) == group.end()){
                if (!BFS_check(node, graph, group)){
                    return false;
                }
            }
        }
        return true;
    }




    bool BFS_check(int start, vector<vector<int>>& graph, unordered_map<int, int>&group){

        queue<int> q;
        q.push(start);
        group[start] = 0;

        while(!q.empty()){
            int v = q.front();
            int current_group = group[v];


            for (int w: graph[v]){
                if (group.find(w) == group.end()){
                    //not exist
                    q.push(w);
                    group[w] = 1- current_group;

                }
                else if(group[w] == current_group){
                    return false;
                }
            }

        }   
        return true;
    }

};




int main() {
    vector<vector<int>> graph1 = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    vector<vector<int>> graph2 = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    Solution sol;
    cout << (sol.isBipartite(graph1) ? "True" : "False") << endl; // True
    cout << (sol.isBipartite(graph2) ? "True" : "False") << endl; // False

    return 0;
}
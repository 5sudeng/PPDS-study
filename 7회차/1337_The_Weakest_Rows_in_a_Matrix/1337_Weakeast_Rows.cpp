
#include<iostream>
#include<vector>
#include<queue>
#include <numeric> // for std::accumulate

using namespace std;

class Solution {

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        

        //기본 max heap -> 오름차순으로 : <sum, index>
        priority_queue<pair<int , int>, vector<pair<int, int>>, greater<>> Q;

        for(int i = 0; i<mat.size(); i++){

            int sum = 0;
            for(auto c : mat[i]){
                sum += c;
            }

            //int sum = std::accumulate(vec.begin(), vec.end()-1, 0);
            Q.push({sum, i});
        }

        //
        vector<int> ans;
        for (int j = 0; j<k; j++){
            
            auto top = Q.top();
            Q.pop();
            ans.push_back(top.second);

        }

    return ans;
    }
};
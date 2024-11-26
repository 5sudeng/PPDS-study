#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    // 1. with two priority queues
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers = 0;

        // min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> on;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> off;
        for (auto trip : trips) {
            on.push({trip[1], trip[0]});  // 어디서 몇 명이 타는지
            off.push({trip[2], trip[0]}); // 어디서 몇 명이 내리는지
        }

        while (!on.empty() && !off.empty()) {
            if (on.top().first < off.top().first) {
                passengers += on.top().second; on.pop();
                if (passengers > capacity) { return false; }
            } else {
                passengers -= off.top().second; off.pop();
            }
        }

        if (!on.empty()) {
            passengers += on.top().second; on.pop();
            if (passengers > capacity) { return false; }
        }

        return true;
    }
    
    // 2. with one priority queue (faster!)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> onoff;
        for (auto trip : trips) {
            onoff.push({trip[1], trip[0]});
            onoff.push({trip[2], -trip[0]});
        }

        while (!onoff.empty()) {
            passengers += onoff.top().second; onoff.pop();
            if (passengers > capacity) { return false; }
        }
        
        return true;
    }

    // 3. map으로도 할 수 있다고 한다 ~

};

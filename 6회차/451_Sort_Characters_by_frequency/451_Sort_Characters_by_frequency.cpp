#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
    
        
        map<char, int>hash;
        //counting : alrotihm module

        for (char c : s){
            
            hash[c]++;
        } // ordered in ascending by character.... 빈도를 기반으로 다시 정렬 필요 그래서 priority queue가 필요
        //

        //max heap: decreasing order : 원래 priority queue 자체가 max heap 임.
        priority_queue<pair<int, char>>Q;
        for(auto it : hash){
            Q.push({it.second, it.first}); // int, char
        }

        //reverse order append
        string ans ="";
        while(!Q.empty()){
            auto top = Q.top();
            Q.pop();
            ans+=string(top.first, top.second); //repeat
        }
        
        return ans;
    }

    string frequencySort2(string s) {
        
        /*
        set을 쓰는 방법도 있음.
        set은 value을 기준으로 기본 ascending이니...
        */
    
        
        map<char, int>hash;
        //counting : alrotihm module

        for (char c : s){
            
            hash[c]++;
        } // ordered in ascending by character.... 빈도를 기반으로 다시 정렬 필요 그래서 priority queue가 필요
        //

        //max heap: decreasing order : 원래 priority queue 자체가 max heap 임.
        set<pair<int, char>, greater<>> sortedSet; // int를 기준으로 내림차순 정렬
        /*
        set : pair<int, char> 을 보고 <int>을 기준으로 정렬(기본은 오름차순)
        greater<> : 내림차순 :(큰값 -> 작은 값)
        */

        for(auto it : hash){
            sortedSet.insert({it.second, it.first}); // int, char
        }

        //reverse order append
        string ans ="";
        for(auto it : sortedSet){
            ans+=string(it.first, it.second); //repeat

        }
        
        return ans;
    }

};

int main(){

    string s= "Aabb";

    Solution sol;
    cout<<sol.frequencySort(s)<<endl;


    return -1;
}
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:

    bool binary_search(vector<int>& L, int target);
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();


        for(int i=0; i<m; i++){
            if (binary_search(matrix[i], target)){
                return true;
            }
        }
        return false;
    }


    
};

bool Solution::binary_search(vector<int>& L, int target){
    int start = 0;
    int end = L.size() -1;

    while(start <= end){
        int mid = (start + end) / 2;

        if (L[mid] == target){
            return true;
        }

        else if (L[mid] < target){
            start = mid +1;
        }
        else{
            end = mid -1;
        }
    }
    return false;
}


int main(){

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 9;
    Solution sol;
    cout<<sol.searchMatrix(matrix, target)<<endl;

    return 0;
}



#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,0 ); // {개수, 값}

        if (n==1){
            return nums[0];
        }

        dp[0] = nums[0];
        if (nums[0] > nums[1]){
            dp[1] = nums[0];
        }
        else{
            dp[1] = nums[1];
        }
        
        for(int i = 2; i <n; i++){
            if (dp[i-2] + nums[i] > dp[i-1]){
                dp[i] = dp[i-2] + nums[i];
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};


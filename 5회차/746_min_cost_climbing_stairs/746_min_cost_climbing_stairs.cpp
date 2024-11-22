class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = cost;
        int n = cost.size();
        
        for(int i = 2 ; i < n ; i++){
            if (dp[i-2] < dp[i-1]){
                dp[i] = dp[i-2] + dp[i];
            }
            else {
                dp[i] = dp[i-1] + dp[i];
            }
        }

        if (dp[n-1] < dp[n-2]){
            return dp[n-1];
        }
        else{
            return dp[n-2];
        }
    }
};
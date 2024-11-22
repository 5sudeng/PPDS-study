int minCostClimbingStairs(int* cost, int costSize) {
    int* dp = cost;

    for (int i = 2; i < costSize; i++){
        if (dp[i-2] < dp[i-1]){
            dp[i] += dp[i-2];
        }
        else {
            dp[i] += dp[i-1];
        }
    }

    if (dp[costSize-1] < dp[costSize-2]){
        return dp[costSize-1];
    }
    else {
        return dp[costSize-2];
    }
}
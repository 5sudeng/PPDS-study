#include<stdio.h>
#include<stdlib.h>


int rob(int* nums, int numsSize) {
    
    int dp[numsSize];

    if (numsSize ==1){
        return nums[0];
    }

    dp[0] = nums[0];
            
    if (nums[0] > nums[1]){
        dp[1] = nums[0];
    }
    else{
        dp[1] = nums[1];
    }
        
    for(int i = 2; i <numsSize; i++){
        if (dp[i-2] + nums[i] > dp[i-1]){
            dp[i] = dp[i-2] + nums[i];
        }
        else{
            dp[i] = dp[i-1];
        }
    }
    
    return dp[numsSize-1];
    


}
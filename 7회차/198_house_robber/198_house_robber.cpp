class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;               // 집이 없는 경우
        if (n == 1) return nums[0];         // 집이 하나만 있는 경우
        
        // DP 배열 초기화
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // DP 테이블 채우기
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]); // 현재 집을 털까 말까
        }

        // 최종 결과 반환
        return dp[n - 1];
    }
};


// dp 배열 사용하지 않고 공간 복잡도 줄인 버전
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
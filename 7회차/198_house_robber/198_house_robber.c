#include <stdio.h>
#include <stdlib.h>

// House Robber 함수
int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;           // 빈 입력 처리
    if (numsSize == 1) return nums[0];     // 집이 하나인 경우

    int prev2 = nums[0];                   // dp[i-2]: 첫 번째 집만 털 경우
    int prev1 = nums[0] > nums[1] ? nums[0] : nums[1]; // dp[i-1]: 첫 두 집 중 최댓값

    for (int i = 2; i < numsSize; i++) {
        int curr = prev1 > (nums[i] + prev2) ? prev1 : (nums[i] + prev2); // dp[i] 계산
        prev2 = prev1;               // dp[i-2] 갱신
        prev1 = curr;                // dp[i-1] 갱신
    }

    return prev1;                    // 최종 결과 반환
}

// 테스트 함수
int main() {
    int nums1[] = {1, 2, 3, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Maximum amount robbed: %d\n", rob(nums1, numsSize1)); // Expected: 4

    int nums2[] = {2, 7, 9, 3, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Maximum amount robbed: %d\n", rob(nums2, numsSize2)); // Expected: 12

    int nums3[] = {2};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Maximum amount robbed: %d\n", rob(nums3, numsSize3)); // Expected: 2

    return 0;
}

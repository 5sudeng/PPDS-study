#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dp[201][201];
    
    int calculate(int start, int end, int n) { 
        //start와 end 사이에 있는 모든 수로 예측 하는 경우의 수 계산. 각 경우에 worst case들 중, 가장 작은 값을 찾는다. 
        //=> 즉 어떤 숫자를 고르는데 min 값의 worst case를 가지는가? 를 찾는 문제.
        if (start == end) return 0;
        if (dp[start][end]) return dp[start][end];

        long ans = INT_MAX;

        for (long i=start; i <= end; i++) {
            // i로 예측한다고 가정!
            long c1 = 0, c2 = 0, c3 = 0; //case 1,2,3
            c1 = 0; //case 1: i가 정답일 때 - 사실 없어도 될 듯
            if (i > 1) { //1로 예측한 경우.. 더 작은 경우의 계산이 필요없기 때문
                c2 = i + calculate(start, i-1, n);
            }
            if (i < n) { //n으로 예측할 경우 더 큰 경우의 계산이 필요없기 때문
                c3 = i + calculate(i+1, end, n);
            }
            ans = min(ans, max({c1, c2, c3}));
        }
        return dp[start][end] = ans;
    }

    int getMoneyAmount(int n) {
        return calculate(1, n, n); //n이 주어졌을 때 1~n에서 찾기
    }
};

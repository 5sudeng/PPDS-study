#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int min(int a, int b, int c) {
        if (b>a && c>a) { return a; }
        else if (c>b) { return b; }
        else { return c; }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));
        int largest = 0;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    if (i==0 || j==0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1;
                    }
                }

                largest = (dp[i][j]>largest)? dp[i][j] : largest;
            }
        }
        return largest*largest;
    }

};
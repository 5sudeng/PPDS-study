#include <string>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        double cnt[] = {0,0,0,0,0};
        double result = 100000;
        char eng[] = {'b', 'a', 'l', 'o', 'n'}; //ba ll oo n
        double values[] = {1, 1, 0.5, 0.5, 1};
        for (auto val: text) {
            for (int i=0; i<5; i++) {
                if (val == eng[i]) {
                    cnt[i] += values[i];
                    break;
                }
            }
        }
        for (auto n: cnt) {
            if (result > n) result = n;
        }
        return int(result);
    }
};
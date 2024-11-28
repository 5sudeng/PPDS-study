#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.push_back(asteroids[0]);

        int idx = 1;
        while (idx < asteroids.size()) {
            
            // ans에 아무것도 들어있지 않으면, 지금 들어온 asteroid를 추가하고 아래 절차를 건너뜀
            if (ans.empty()) {
                ans.push_back(asteroids[idx]);
                idx++;
                continue;
            }

            // collision check
            int old = ans.back(); 
            int curr = asteroids[idx];
            
            if ( (old*curr>0) || (old<0 && curr>0) ) {
                ans.push_back(curr); // no collision
            } else {
                if (abs(old) == abs(curr)) {
                    ans.pop_back(); // remove old
                } else if (abs(old) > abs(curr)) {
                    // do nothing
                } else { // abs(old) < abs(curr)
                    int crashed = 0;
                    while (!ans.empty()) {
                        old = ans.back();
                        if ( (old*curr>0) || (old<0 && curr>0) ) {
                            ans.push_back(curr);
                            break;
                        }

                        if (abs(old) < abs(curr)) {
                            ans.pop_back();
                        } else if (abs(old) == abs(curr)) {
                            ans.pop_back();
                            crashed = 1;
                            break;
                        } else { // abs(old) > abs(curr)
                            // do nothing
                            break;
                        }
                    }
                    if (ans.empty() && crashed==0) { ans.push_back(curr); }
                }
            }

            idx++;
        }
        return ans;
    }
};

/* from GPT

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int curr : asteroids) {
            bool crashed = false;

            while (!ans.empty() && curr < 0 && ans.back() > 0) {
                int old = ans.back();
                
                if (abs(old) < abs(curr)) {
                    ans.pop_back(); // 기존 asteroid 제거
                } else if (abs(old) == abs(curr)) {
                    ans.pop_back(); // 기존 asteroid 제거
                    crashed = true; // 서로 파괴
                    break;
                } else {
                    crashed = true; // curr이 파괴됨
                    break;
                }
            }

            // 충돌하지 않은 경우 추가
            if (!crashed) ans.push_back(curr);
        }

        return ans;
    }
};

*/
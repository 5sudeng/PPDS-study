#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;              
        int m = board.size();       
        int n = board[0].size();         
        
        for (int y = 0; y < m; y++) {           
            for (int x = 0; x < n; x++) {            	
                if (board[y][x] == 'X') {
                    // 이전 행 또는 이전 열에 같은 전투함이 있는 경우 스킵
                    if ((y > 0 && board[y-1][x] == 'X') || (x > 0 && board[y][x-1] == 'X')) {
                        continue;
                    }
                    ans++;  // 새로운 전투함 발견
                }
            }
        }
        return ans;
    }
};

int main() {
    // 입력 데이터 정의
    vector<vector<char>> board = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };

    // Solution 클래스 인스턴스 생성
    Solution sol;

    // 전투함 개수 계산
    int result = sol.countBattleships(board);

    // 결과 출력
    cout << "전투함의 개수: " << result << endl;

    return 0;
}

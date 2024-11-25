#include <stdio.h>

int countBattleships(char board[][4], int m, int n) {
    int ans = 0; // 전투함 개수

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (board[y][x] == 'X') {
                // 이전 행 또는 이전 열에 같은 전투함이 있는 경우 스킵
                if ((y > 0 && board[y - 1][x] == 'X') || (x > 0 && board[y][x - 1] == 'X')) {
                    continue;
                }
                ans++; // 새로운 전투함 발견
            }
        }
    }
    return ans;
}

int main() {
    // 입력 데이터 정의
    char board[3][4] = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };

    int m = 3; // 행 개수
    int n = 4; // 열 개수

    // 전투함 개수 계산
    int result = countBattleships(board, m, n);

    // 결과 출력
    printf("전투함의 개수: %d\n", result);

    return 0;
}

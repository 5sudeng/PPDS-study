#include <stdio.h>
#include <stdlib.h>

int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

// 인접 지뢰 개수 계산 함수
int countAdjacentMines(char** board, int rows, int cols, int r, int c) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nr = r + directions[i][0];
        int nc = c + directions[i][1];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'M') {
            count++;
        }
    }
    return count;
}

// DFS를 사용해 빈 칸을 탐색 및 업데이트하는 함수
void dfs(char** board, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'E') {
        return;
    }

    int mineCount = countAdjacentMines(board, rows, cols, r, c);
    if (mineCount > 0) {
        // 주변에 지뢰가 있는 경우 숫자로 업데이트
        board[r][c] = mineCount + '0';
    } else {
        // 주변에 지뢰가 없는 경우 빈 칸('B')으로 업데이트 후 재귀 탐색
        board[r][c] = 'B';
        for (int i = 0; i < 8; i++) {
            dfs(board, rows, cols, r + directions[i][0], c + directions[i][1]);
        }
    }
}

// 메인 updateBoard 함수
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
    int rows = boardSize;
    int cols = boardColSize[0];  // Assuming all rows have the same number of columns

    // 메모리를 할당하여 결과 보드를 반환
    char** result = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        result[i] = (char*)malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            result[i][j] = board[i][j];
        }
    }

    int click_r = click[0];
    int click_c = click[1];

    if (result[click_r][click_c] == 'M') {
        // 지뢰 클릭 시 게임 종료
        result[click_r][click_c] = 'X';
    } else {
        // 빈 칸 클릭 시 DFS 실행
        dfs(result, rows, cols, click_r, click_c);
    }

    // 반환 크기 설정
    *returnSize = rows;
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
    }

    return result;
}

// 테스트 실행
int main() {
    // 보드 초기화
    char* board[] = {
        "EEEEE",
        "EEMEE",
        "EEEEE",
        "EEEEE"
    };
    int boardSize = 4;
    int boardColSize[] = {5, 5, 5, 5};

    // 클릭 위치
    int click[] = {3, 0};
    int clickSize = 2;

    // 반환 값
    int returnSize;
    int* returnColumnSizes;

    // 보드 업데이트
    char** updatedBoard = updateBoard(board, boardSize, boardColSize, click, clickSize, &returnSize, &returnColumnSizes);

    // 결과 출력
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%c ", updatedBoard[i][j]);
        }
        printf("\n");
    }

    // 메모리 해제
    for (int i = 0; i < returnSize; i++) {
        free(updatedBoard[i]);
    }
    free(updatedBoard);
    free(returnColumnSizes);

    return 0;
}

#include "backtracking.h"

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// 해당 위치에 퀸을 놓을 수 있는지 확인하는 함수
bool isSafe(int board[N][N], int row, int col) {
    // 같은 열에 있는지 확인
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // 왼쪽 위 대각선에 있는지 확인
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // 오른쪽 위 대각선에 있는지 확인
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

// N-Queens 문제를 해결하는 백트래킹 함수
bool solveNQueensUtil(int board[N][N], int row) {
    // 모든 퀸을 놓았을 경우
    if (row == N) {
        printSolution(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            // 현재 위치에 퀸을 놓는다.
            board[row][i] = 1;
            // 다음 행으로 넘어가서 재귀 호출
            res = solveNQueensUtil(board, row + 1) || res;
            // 퀸을 놓은 위치가 해결책이 아니면 다시 원상복구
            board[row][i] = 0;
        }
    }
    return res;
}

// N-Queens 문제를 해결하는 함수
void solveNQueens() {
    int board[N][N];
    // 체스판 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist.\n");
    }
}
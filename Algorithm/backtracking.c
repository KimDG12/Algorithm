#include "backtracking.h"

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// �ش� ��ġ�� ���� ���� �� �ִ��� Ȯ���ϴ� �Լ�
bool isSafe(int board[N][N], int row, int col) {
    // ���� ���� �ִ��� Ȯ��
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // ���� �� �밢���� �ִ��� Ȯ��
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // ������ �� �밢���� �ִ��� Ȯ��
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

// N-Queens ������ �ذ��ϴ� ��Ʈ��ŷ �Լ�
bool solveNQueensUtil(int board[N][N], int row) {
    // ��� ���� ������ ���
    if (row == N) {
        printSolution(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i)) {
            // ���� ��ġ�� ���� ���´�.
            board[row][i] = 1;
            // ���� ������ �Ѿ�� ��� ȣ��
            res = solveNQueensUtil(board, row + 1) || res;
            // ���� ���� ��ġ�� �ذ�å�� �ƴϸ� �ٽ� ���󺹱�
            board[row][i] = 0;
        }
    }
    return res;
}

// N-Queens ������ �ذ��ϴ� �Լ�
void solveNQueens() {
    int board[N][N];
    // ü���� �ʱ�ȭ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist.\n");
    }
}
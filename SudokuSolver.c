#include <stdio.h>
#define N 9

void PrintBoard(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d", board[row][col]);
        }
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col, int num) {
    // checking column and row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    // 3x3 box or not
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (board[startRow + j][startCol + k] == num) {
                return 0;
            }
        }
    }
    }
    return 1;
}

int Solve(int board[N][N]) {
    int empty = 0;
    int row, col;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if(board[row][col] == 0) {
                empty = 1;
                break;
            }
        }
        if(empty) {
            break;
        }
    }
    if(!empty) {
        return 1;
    }

    for (int num = 1; num < 10; num++) {
        if(isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (Solve(board)) {
                return 1;
            }
        board[row][col] = 0;
        }  
    }
    return 0; // for backtracking, goes to Solve(board) as false and tries again.
}

int main() {
    int board[N][N] = {
        {1, 0, 0, 5, 0, 0, 6, 0, 0},
        {0, 2, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 8, 0, 2, 6, 0, 0, 3},
        {9, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 6, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 4, 1, 3, 0, 0},
        {0, 0, 5, 0, 0, 0, 0, 4, 0},
        {0, 4, 0, 0, 3, 2, 1, 0, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 0}
    };

    if (Solve(board)) {
        PrintBoard(board);
    }

    else {
        printf("Solution is not possible.");
    }
    return 0;
}
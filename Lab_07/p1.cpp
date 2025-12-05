#include <bits/stdc++.h>
using namespace std;

int board[8][8];

bool isSafe(int row, int col) {

    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1) return false;

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++)
        if (board[i][j] == 1) return false;

    return true;
}

void solve(int row) {
    if (row == 8) {
        // Print solution
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << "----------------------\n";
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;       // place queen
            solve(row + 1);            // solve next row
            board[row][col] = 0;       // backtrack
        }
    }
}

int main() {
    solve(0);
    return 0;
}

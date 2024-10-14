#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(int row, int n, vector<int>& queens, vector<vector<string>>& solutions);
bool isValid(int row, int col, const vector<int>& queens);

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> queens(n, -1); // To store column positions of queens
    backtrack(0, n, queens, solutions);
    return solutions;
}

void backtrack(int row, int n, vector<int>& queens, vector<vector<string>>& solutions) {
    if (row == n) {
        // If all queens are placed, create a solution board
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][queens[i]] = 'Q';
        }
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isValid(row, col, queens)) {
            queens[row] = col; // Place the queen
            backtrack(row + 1, n, queens, solutions); // Recur to place the next queen
            queens[row] = -1; // Backtrack
        }
    }
}

bool isValid(int row, int col, const vector<int>& queens) {
    for (int i = 0; i < row; ++i) {
        // Check if the column or diagonals are threatened
        if (queens[i] == col || 
            queens[i] - i == col - row || 
            queens[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 4; // Change this value for different sizes of the board
    vector<vector<string>> solutions = solveNQueens(n);

    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

const int N = 8; // chessboard size

// Helper function to check if a queen can be placed on board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col) {
    for (int j = 0; j < col; j++) {
        if (board[row][j] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

// Function to solve the 8 queens problem
bool solveNQueens(vector<vector<int>>& board, int col) {
    // Base case: if all queens are placed, return true
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, col + 1))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // backtrack and remove the queen from board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0)) {
        cout << "Solution :\n";
        printBoard(board); // Print the solution
    } else {
        cout << "No solution\n";
    }

    return 0;
}

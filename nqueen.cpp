#include <iostream>
using namespace std;

#define MAX 10  // Define maximum board size

int board[MAX][MAX];  // Create a 2D array to represent the chessboard

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    // Check this column in the previous rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to print the solution
void printSolution(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << endl;
}

// Recursive function to solve the N-Queen problem
bool solveNQueens(int board[MAX][MAX], int row, int n) {
    if (row >= n) {
        printSolution(board, n);  // A solution found, print the board
        return true;
    }

    bool result = false;  // To check if at least one solution exists
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place queen

            // Recur to place rest of the queens
            result = solveNQueens(board, row + 1, n) || result;

            // If placing queen at board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0;  // Remove queen
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    if (n > MAX) {
        cout << "Board size too large! Please enter a size up to " << MAX << "." << endl;
        return 0;
    }

    // Initialize the board to 0 (no queens placed)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the N-Queens problem
    if (!solveNQueens(board, 0, n)) {
        cout << "No solution exists for " << n << "-Queens." << endl;
    }

    return 0;
}


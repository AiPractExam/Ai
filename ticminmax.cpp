#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char player = 'X';

// Function to display the Tic-Tac-Toe board
void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if any player has won
int checkWin() {
    // Rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return (board[i][0] == 'X') ? 10 : -10;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return (board[0][i] == 'X') ? 10 : -10;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return (board[0][0] == 'X') ? 10 : -10;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return (board[0][2] == 'X') ? 10 : -10;
    
    return 0; // No winner yet
}

// Function to check if there are moves remaining on the board
bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
    return false;
}

// Minimax function to calculate the best move
int minimax(bool isMax) {
    int score = checkWin();

    // If Maximizer (X) has won
    if (score == 10) return score;

    // If Minimizer (O) has won
    if (score == -10) return score;

    // If no moves left and no winner
    if (!isMovesLeft()) return 0;

    if (isMax) {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Check if cell is empty
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char temp = board[i][j]; // Save current cell
                    board[i][j] = 'X'; // Make the move

                    // Call minimax recursively and choose the maximum value
                    best = max(best, minimax(false));

                    // Undo the move
                    board[i][j] = temp;
                }
            }
        }
        return best;
    } else {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Check if cell is empty
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char temp = board[i][j]; // Save current cell
                    board[i][j] = 'O'; // Make the move

                    // Call minimax recursively and choose the minimum value
                    best = min(best, minimax(true));

                    // Undo the move
                    board[i][j] = temp;
                }
            }
        }
        return best;
    }
}

// Function to find the best move for the AI
int findBestMove() {
    int bestVal = -1000;
    int bestMove = -1;

    // Traverse all cells, evaluate minimax for each, and find the best move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Check if cell is empty
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char temp = board[i][j]; // Save current cell
                board[i][j] = 'X'; // Make the move

                // Compute evaluation of this move
                int moveVal = minimax(false);

                // Undo the move
                board[i][j] = temp;

                // If the value of the current move is more than the best value, update best
                if (moveVal > bestVal) {
                    bestMove = (i * 3) + (j + 1);
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

// Function to make a move for the player
void makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        player = (player == 'X') ? 'O' : 'X';
    } else {
        cout << "Invalid move! Try again.\n";
    }
}

int main() {
    int move;

    while (true) {
        displayBoard();

        if (checkWin() == 10) {
            cout << "AI (X) wins!\n";
            break;
        } else if (checkWin() == -10) {
            cout << "You (O) win!\n";
            break;
        } else if (!isMovesLeft()) {
            cout << "It's a draw!\n";
            break;
        }

        if (player == 'O') {
            cout << "Enter your move (1-9): ";
            cin >> move;
            makeMove(move);
        } else {
            cout << "AI is making a move...\n";
            move = findBestMove();
            makeMove(move);
        }
    }

    displayBoard();
    return 0;
}


#include <iostream>
#include <algorithm> // for min and max functions
#include <conio.h>   // for getch()

using namespace std;

const int MAX = 1000;
const int MIN = -1000;

// Function to implement Minimax algorithm with Alpha-Beta pruning
int minimax(int depth, int nodeIndex, bool isMaxPlayer, int values[], int alpha, int beta) {
    // Terminal condition: If a leaf node is reached
    if (depth == 3) { // Assuming depth 3 is the leaf node level
        return values[nodeIndex];
    }

    // Maximizer's move
    if (isMaxPlayer) {
        int best = MIN; // Initialize the best value for maximizer

        // Recur for left and right children
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i, false, values, alpha, beta);
            best = max(best, val); // Select the maximum value for maximizer
            alpha = max(alpha, best); // Update alpha

            // Alpha-Beta Pruning: Prune if beta is less than or equal to alpha
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    } 
    // Minimizer's move
    else {
        int best = MAX; // Initialize the best value for minimizer

        // Recur for left and right children
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta);
            best = min(best, val); // Select the minimum value for minimizer
            beta = min(beta, best); // Update beta

            // Alpha-Beta Pruning: Prune if beta is less than or equal to alpha
            if (beta <= alpha) {
                break;
            }
        }
        return best;
    }
}

int main() {
    // Values at the leaf nodes of the game tree
    int values[] = {3, 9, 64, 5, 89, 61, 2, 0};

    cout << "The optimal value is: " 
         << minimax(0, 0, true, values, MIN, MAX) << endl;

    getch();  // Wait for a key press
    return 0;
}


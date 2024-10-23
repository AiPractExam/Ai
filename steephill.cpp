#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

void printArray(int array[3][3]) {
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            cout << array[a][b] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int manhattan(int ini[3][3], int fin[3][3]) {
    int m = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ini[i][j] > 0) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (fin[k][l] == ini[i][j]) {
                            m += abs(i - k) + abs(j - l);
                        }
                    }
                }
            }
        }
    }
    return m;
}

void makeMove(int temp[3][3], int move) {
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (temp[i][j] == -1) {
                if (move == 1 && i > 0) {
                    temp[i][j] = temp[i - 1][j];
                    temp[i - 1][j] = -1;
                    flag = 1;
                    break;
                } else if (move == 2 && i < 2) {
                    temp[i][j] = temp[i + 1][j];
                    temp[i + 1][j] = -1;
                    flag = 1;
                    break;
                } else if (move == 3 && j > 0) {
                    temp[i][j] = temp[i][j - 1];
                    temp[i][j - 1] = -1;
                    flag = 1;
                    break;
                } else if (move == 4 && j < 2) {
                    temp[i][j] = temp[i][j + 1];
                    temp[i][j + 1] = -1;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) break;
    }
}

int childTraverse(int curr[3][3], int fin[3][3], int move) {
    int temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = curr[i][j];
        }
    }
    makeMove(temp, move);
    printArray(temp);
    int man = manhattan(temp, fin);
    cout << "The Manhattan number for this child is: " << man << endl << endl;
    return man;
}

void steepestHillClimb(int ini[3][3], int fin[3][3], int previous) {
    int arr[4];
    cout << endl;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ini[i][j] == -1) {
                if (i > 0 && previous != 2) {
                    cout << "Checking child (moving up)" << endl;
                    arr[0] = childTraverse(ini, fin, 1);
                }
                if (i < 2 && previous != 1) {
                    cout << "Checking child (moving down)" << endl;
                    arr[1] = childTraverse(ini, fin, 2);
                }
                if (j > 0 && previous != 4) {
                    cout << "Checking child (moving left)" << endl;
                    arr[2] = childTraverse(ini, fin, 3);
                }
                if (j < 2 && previous != 3) {
                    cout << "Checking child (moving right)" << endl;
                    arr[3] = childTraverse(ini, fin, 4);
                }
            }
        }
    }
    
    int locOpt = 99;
    int index = 0;
    
    for (int i = 0; i < 4; i++) {
        if (arr[i] < locOpt) {
            locOpt = arr[i];
            index = i + 1;
        }
    }
    
    makeMove(ini, index);
    cout << "Next state (the one with minimum Manhattan number): " << endl;
    printArray(ini);
    
    if (locOpt == 0) {
        cout << "Solved! :)" << endl;
        return;
    } else {
        steepestHillClimb(ini, fin, index);
    }
}

int main() {
    int initial[3][3], final[3][3], ue;

    // Input the initial matrix
    cout << "Enter initial 3x3 matrix (-1 as empty position)\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> initial[i][j];
        }
    }

    // Input the final matrix
    cout << "Enter final 3x3 matrix (-1 as empty position)\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> final[i][j];
        }
    }

    // Display the matrices
    cout << "\nYour initial matrix is:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << initial[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nYour final matrix is:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << final[i][j] << "\t";
        }
        cout << endl;
    }

    // Call the steepest hill climb function
    cout << "Calling SHC function...\n";
    steepestHillClimb(initial, final, 0);
    getch();
    return 0;
}


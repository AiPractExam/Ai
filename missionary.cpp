#include <iostream>
using namespace std;

int m = 3, c = 3, fm = 0, fc = 0, flag = 0, select = 0;

// Function to display the current state of the boat and passengers
void display(char bpass1, char bpass2) {
    if (flag == 0) { // Boat on the left
        cout << "Boat on left side with: " << bpass1 << ", " << bpass2 << endl;
    } else { // Boat on the right
        cout << "Boat on right side with: " << bpass1 << ", " << bpass2 << endl;
    }
    cout << "Missionaries on left: " << m << ", Cannibals on left: " << c << endl;
    cout << "Missionaries on right: " << fm << ", Cannibals on right: " << fc << endl;
}

// Function to check if all have crossed the river
int win() {
    if (fm == 3 && fc == 3) return 0; // Win condition
    else return 1;
}

// Function to solve the problem step-by-step
void solution() {
    while (win()) {
        if (flag == 0) { // Boat on left side
            if (m >= 2) { // Move 2 missionaries
                select = 1;
                m -= 2;
                fm += 2;
                display('M', 'M');
            } else if (c >= 2) { // Move 2 cannibals
                select = 2;
                c -= 2;
                fc += 2;
                display('C', 'C');
            } else if (m >= 1 && c >= 1) { // Move 1 missionary and 1 cannibal
                select = 3;
                m -= 1;
                c -= 1;
                fm += 1;
                fc += 1;
                display('M', 'C');
            }
            flag = 1; // Boat goes to the right
        } else { // Boat on right side
            if (select == 1) { // Move 2 missionaries back
                fm -= 2;
                m += 2;
                display('M', 'M');
            } else if (select == 2) { // Move 2 cannibals back
                fc -= 2;
                c += 2;
                display('C', 'C');
            } else if (select == 3) { // Move 1 missionary and 1 cannibal back
                fm -= 1;
                fc -= 1;
                m += 1;
                c += 1;
                display('M', 'C');
            }
            flag = 0; // Boat goes back to the left
        }
    }
    cout << "All missionaries and cannibals have successfully crossed the river!" << endl;
}

int main() {
    cout << "MISSIONARIES AND CANNIBALS PROBLEM" << endl;
    solution();
    return 0;
}


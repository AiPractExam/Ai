#include <iostream>
using namespace std;

// Global variables for jug capacities
int xcapacity, ycapacity;

// Function to display the current amount of water in both jugs
void display(int a, int b) {
    cout << "\t" << a << "\t" << b << endl;
}

// Function to return the minimum of two values
int min(int d, int f) {
    if(d<f)
    return d;
    else
    return f;
}

// Function to calculate steps to measure exactly 'n' liters in any of the jugs
int steps(int n) {
    int x = 0, y = 0, step = 0, temp;
    
    cout << "\tJar A\tJar B" << endl;
    
    // Loop until one of the jugs contains exactly 'n' liters
    while (x != n ) {
        if (x == 0) {
            // Fill Jug A
            x = xcapacity;
            step++;
            cout << "\nFill A   ";
            display(x, y);
        } 
        else if (y == ycapacity) {
            // Empty Jug B
            y = 0;
            step++;
            cout << "\nEmpty B   ";
            display(x, y);
        } 
        else {
            // Pour water from Jug A to Jug B
            temp = min(ycapacity - y, x);
            y += temp;
            x -= temp;
            step++;
            cout << "\nPour A into B";
            display(x, y);
        }
    }
    
    return step;
}

int main() {
    int n, ans;
    
    // Input: The amount of water to be measured (goal)
    cout << "\nEnter the goal (liters of water required): ";
    cin >> n;
    
    // Input: Capacities of both jugs
    cout << "\nEnter the capacity of Jar A: ";
    cin >> xcapacity;
    
    cout << "\nEnter the capacity of Jar B: ";
    cin >> ycapacity;
    
    // Calculate and display the number of steps required
    ans=steps(n);
    
    cout << "\nSteps Required: " << ans << endl;
    
    return 0;
}


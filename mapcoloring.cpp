#include <iostream>
#include <conio.h>
using namespace std;

int a, number;  // 'a' is the number of colors, 'number' is the number of vertices
int G[20][20], c[20];  // G is the adjacency matrix, c is the color assignment array

void mcoloring(int p);
int nextvalue(int p);

void mcoloring(int p) {
    int u;
    while (1) {
        nextvalue(p);  // Get the next color for vertex p
        if (c[p] == 0)  // If no color can be assigned, break
            break;
        if (p == number) {  // If all vertices are colored, print the solution
            for (u = 1; u <= number; u++) {
                cout << " " << c[u];
            }
            cout << "\n";
        } else {
            mcoloring(p + 1);  // Move to the next vertex
        }
    }
}

int nextvalue(int p) {
    int i;
    while (1) {
        c[p] = (c[p] + 1) % (a + 1);  // Assign the next color
        if (c[p] == 0)  // If no color can be assigned, return 0
            return 0;
        for (i = 1; i <= number; i++) {
            // Check if adjacent vertices have the same color
            if (G[p][i] && c[p] == c[i])
                break;
        }
        if (i == number + 1)  // If no adjacent vertices have the same color, return
            return 1;
    }
}

int main() {
    cout << "Enter the number of vertices in the graph: ";
    cin >> number;

    int u, edges, x, y;
    cout << "Enter the number of edges in the graph G: ";
    cin >> edges;

    // Initialize the adjacency matrix
    for (u = 1; u <= edges; u++) {
        cout << "Enter the edge in the graph (x y): ";
        cin >> x >> y;
        G[x][y] = 1;
        G[y][x] = 1;
    }

    // Initialize all vertex colors to 0 (no color)
    for (u = 1; u <= number; u++) {
        c[u] = 0;
    }

    cout << "Enter the number of colors available: ";
    cin >> a;

    cout << "Following are the different ways by which nodes can be colored:\n";
    mcoloring(1);

    getch();  // Wait for a key press before exiting
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int i, j, k, v, iv, ed, t = 0; // Variables for vertices, edges, and stack management
    int stk[10], a[10][10] = {0}; // Stack and adjacency matrix initialization

    cout << "Enter number of vertices\n";
    cin >> v; // Input number of vertices

    cout << "Enter number of edges\n";
    cin >> ed; // Input number of edges

    cout << "Enter all edges\n";
    // Input edges and populate the adjacency matrix
    for (k = 1; k <= ed; k++) {
        cin >> i >> j;
        a[i][j] = 1; // Marking the edge in adjacency matrix
        a[j][i] = 1; // Since it's an undirected graph, mark both directions
    }

    cout << "Enter initial vertex\n";
    cin >> iv; // Input the initial vertex
    cout << iv << " ";

    k = 1; // Counter for visited vertices
    while (k < v) {
        for (j = v; j >= 1; j--) { // Traverse all vertices in reverse order
            if (a[iv][j] != 0) { // If there's an edge from the current vertex to vertex `j`
                a[iv][j] = a[j][iv] = 0; // Mark the edge as visited (set to 0 to avoid revisiting)
                stk[t] = j; // Push the vertex to stack
                t++; // Increment stack pointer
            }
        }

        if (t == 0) {
            break; // If stack is empty, exit the loop
        }

        iv = stk[--t]; // Pop the last vertex from the stack
        cout << iv << " "; // Print the current vertex
        k++; // Increment the visited vertex counter
    }

    return 0; // Wait for user input before closing
}


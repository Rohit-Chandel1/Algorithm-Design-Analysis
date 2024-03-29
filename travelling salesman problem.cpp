#include <iostream>
#include <vector>
#include <algorithm> 
#include <limits>    
using namespace std;

const int V = 4; // Number of vertices

// Function to find the minimum weight Hamiltonian Cycle
int travellingSalesman(const int graph[][V], int source) {
    vector<int> vertices;
    for (int i = 0; i < V; ++i) {
        if (i != source)
            vertices.push_back(i);
    }

    int minPath = numeric_limits<int>::max(); 
    
    do {
        int currentPath = 0; // Current path weight
        int k = source;
        for (int i = 0; i < vertices.size(); ++i) {
            currentPath += graph[k][vertices[i]];
            k = vertices[i];
        }
        currentPath += graph[k][source]; // Return to source vertex

        minPath = min(minPath, currentPath); 

    } while (next_permutation(vertices.begin(), vertices.end()));

    return minPath;
}

int main() {
    // Input: Change the graph representation here
    int graph[V][V] = {
        {0, 15, 20, 0},
        {20, 0, 35, 25},
        {35, 25, 0, 20},
        {10, 20, 30, 0}
    };
    int source = 0; // Source vertex
    cout << "Minimum weight: " << travellingSalesman(graph, source) << endl;
    return 0;
}

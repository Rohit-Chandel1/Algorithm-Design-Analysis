#include <iostream>
#include <climits>

using namespace std;

class MinimumSpanningTree {
public:
    // Function to find the vertex with the minimum key value
    int minKey(int key[], bool mstSet[], int V) {
        int min = INT_MAX, min_index = -1;
        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        return min_index;
    }

    // Function to construct and print the Minimum Spanning Tree
    void minimumSpanningTree(int graph[][5], int V) {
        int parent[V]; 
        int key[V];    
        bool mstSet[V];

        // Initialize key values as INFINITE, MST set as false, and parent as -1
        for (int i = 0; i < V; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
            parent[i] = -1;
        }

        // Start from vertex 0
        key[0] = 0;
        parent[0] = -1; 

        // Construct MST with V-1 edges
        for (int count = 0; count < V - 1; count++) {
            // Pick the minimum key vertex from the set of vertices not yet included in MST
            int u = minKey(key, mstSet, V);
            mstSet[u] = true; // Add the picked vertex to the MST set

            // Update key value and parent index of the adjacent vertices of the picked vertex
            for (int v = 0; v < V; v++)
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
        }

        // Print the edges of the MST along with their weights
        cout << "Edge \tWeight" << endl;
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
            totalWeight += graph[i][parent[i]];
        }
        cout << "Total Weight of MST: " << totalWeight << endl; // Print the total weight of MST
    }
};

int main() {
    MinimumSpanningTree t;
    int graph[5][5] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    int V = 5; 
    t.minimumSpanningTree(graph, V); 
    return 0;
}

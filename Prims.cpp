#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

#define V 5  // Number of vertices in the graph

int findMinVertex(vector<int>& key, vector<bool>& inMST) {
    int minKey = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primsMST(int graph[V][V]) {
    vector<int> parent(V, -1);  // To store the MST
    vector<int> key(V, INT_MAX);  // To store minimum weights
    vector<bool> inMST(V, false);  // To track vertices included in MST

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinVertex(key, inMST);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    // Example graph (adjacency matrix)
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primsMST(graph);
    return 0;
}

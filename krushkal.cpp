#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e4; // Maximum number of nodes
int parent[MAX];

// Find function with path compression
int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

// Union function for union by rank
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV)
        parent[rootU] = rootV;
}

int kruskal(int n, vector<pair<int, pair<int, int>>>& edges) {
    int mst_cost = 0;
    sort(edges.begin(), edges.end()); // Sort edges by weight

    // Initialize each node to be its own parent
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // Check if u and v are in the same set
        if (find(u) != find(v)) {
            mst_cost += weight;
            unionSets(u, v);
        }
    }
    return mst_cost;
}

int main() {
    int n = 4; // Number of nodes
    vector<pair<int, pair<int, int>>> edges = {
        {10, {0, 1}}, {6, {0, 2}}, {5, {0, 3}}, {15, {1, 3}}, {4, {2, 3}}
    };

    cout << "Minimum Cost of MST: " << kruskal(n, edges) << endl;
    return 0;
}

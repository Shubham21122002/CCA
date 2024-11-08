#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int findParent(int u, vector<int>& parent) {
    if (u != parent[u])
        parent[u] = findParent(parent[u], parent);
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    int mstWeight = 0;
    for (const auto& edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            mstWeight += edge.weight;
            unionSets(edge.u, edge.v, parent, rank);
            cout << "Edge: " << edge.u << " - " << edge.v << " | Weight: " << edge.weight << endl;
        }
    }
    return mstWeight;
}

int main() {
    int n = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    int mstWeight = kruskal(n, edges);
    cout << "Total weight of MST: " << mstWeight << endl;
    return 0;
}

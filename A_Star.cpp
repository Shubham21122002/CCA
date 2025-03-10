#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>  // Added for reverse()

using namespace std;

#define INF INT_MAX

// Number of nodes
const int V = 6;

// Predefined heuristic values (Estimated cost to reach goal)
int heuristic[V] = {10, 8, 6, 5, 3, 0};  // h[start] to h[goal]

// A* Algorithm for Directed Graph
void AStar(int start, int goal, vector<pair<int, int>> graph[V]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> gScore(V, INF);
    vector<int> parent(V, -1);

    // Start node setup
    gScore[start] = 0;
    pq.push({heuristic[start], start});

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        if (current == goal) {
            cout << "Path found: ";
            vector<int> path;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            reverse(path.begin(), path.end());
            for (int node : path) cout << node << " -> ";
            cout << "Goal" << endl;
            return;
        }

        // Explore neighbors
        for (auto neighbor : graph[current]) {
            int next = neighbor.first;
            int cost = neighbor.second;

            int newG = gScore[current] + cost;
            if (newG < gScore[next]) {
                gScore[next] = newG;
                int f = newG + heuristic[next];  // f = g + h
                pq.push({f, next});
                parent[next] = current;
            }
        }
    }

    cout << "No path found!" << endl;
}

int main() {
    vector<pair<int, int>> graph[V];

    // Directed Graph (From → To, Cost)
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({3, 7});
    graph[1].push_back({4, 3});
    graph[2].push_back({4, 1});
    graph[3].push_back({5, 1});
    graph[4].push_back({5, 5});

    int start = 0, goal = 5;
    AStar(start, goal, graph);

    return 0;
}

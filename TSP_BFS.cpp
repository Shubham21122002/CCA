#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct State {
    int city;     // Current city
    int mask;     // Bitmask representing visited cities
    int cost;     // Total cost
    vector<int> path;  // Path of cities visited so far
};

int tspBFS(vector<vector<int>> &graph, int start, vector<int> &optimalRoute) {
    int n = graph.size();
    queue<State> q;
    q.push({start, 1 << start, 0, {start}});  // Start from initial city with only it visited

    int minCost = INT_MAX;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // If all cities are visited, return to start city
        if (current.mask == (1 << n) - 1) {
            int totalCost = current.cost + graph[current.city][start];
            if (totalCost < minCost) {
                minCost = totalCost;
                optimalRoute = current.path;  // Update optimal route
                optimalRoute.push_back(start);  // Add the starting city to complete the cycle
            }
            continue;
        }

        // Explore next cities
        for (int next = 0; next < n; next++) {
            if (!(current.mask & (1 << next)) && graph[current.city][next] > 0) {
                vector<int> newPath = current.path;
                newPath.push_back(next);
                q.push({next, current.mask | (1 << next), current.cost + graph[current.city][next], newPath});
            }
        }
    }

    return minCost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int startCity = 0;
    vector<int> optimalRoute;
    int minCost = tspBFS(graph, startCity, optimalRoute);

    if (minCost == INT_MAX) {
        cout << "No solution found." << endl;
    } else {
        cout << "Minimum cost of TSP: " << minCost << endl;
        cout << "Optimal route: ";
        for (int city : optimalRoute) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}

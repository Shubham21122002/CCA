#include<iostream>
#include<vector>
using namespace std;
#define INT_MAX 999  // Defining a large value to represent infinity

int n = 4; // Number of cities

// Distance matrix between cities. dist[i][j] represents the distance from city i to city j
int dist[10][10] = {
    {0, 10, 15, 20},  // Distances from city 0 to other cities
    {5, 0, 25, 10},   // Distances from city 1 to other cities
    {16, 30, 0, 5},   // Distances from city 2 to other cities
    {15, 10, 20, 0}   // Distances from city 3 to other cities
};

// visited_all is a bitmask that represents all cities being visited (1111 in binary, or 15 in decimal for 4 cities)
int visited_all = (1<<n)-1;  // 1<<n shifts '1' to the left by 'n' places to create 10000 in binary, then subtract 1 gives 1111 for 4 cities

vector<int> path; // Vector to store the path

// Recursive function to solve the Traveling Salesman Problem
int tsp(int mask, int pos, vector<int>& curr_path) {
    
    // Base case: If all cities are visited, return the distance to the starting city (city 0)
    if(mask == visited_all) {
        curr_path.push_back(0); // Adding the starting city at the end
        return dist[pos][0];
    }

    // Initialize the minimum answer to infinity (INT_MAX)
    int ans = INT_MAX;
    int chosen_city = -1; // To store the city that gives the minimum answer

    // Try to go to any unvisited city
    for(int city = 0; city < n; city++) {
        // Check if the city is unvisited by using bitwise AND operation
        if((mask & (1<<city)) == 0) {
            // Recursively calculate the cost of visiting the city and add it to the current distance
            vector<int> temp_path;
            int newAns = dist[pos][city] + tsp(mask | (1<<city), city, temp_path);
            // Update the minimum answer and the chosen city
            if(newAns < ans) {
                ans = newAns;
                chosen_city = city;
                curr_path = temp_path;
            }
        }
    }

    // Add the current city to the path
    curr_path.push_back(chosen_city);
    
    // Return the minimum cost to visit all cities
    return ans;
}

int main() 
{
    vector<int> curr_path; // Vector to store the final path
    curr_path.push_back(0); // Starting from city 0
    int cost = tsp(1, 0, curr_path); // tsp(1, 0) means we start from city 0, with the initial mask being 0001 (only city 0 is visited)
    
    // Printing the cost
    cout << "Minimum Cost: " << cost << endl;

    // Printing the path
    cout << "Path: ";
    for(int i = 0; i < curr_path.size(); i++) {
        cout << curr_path[i];
        if(i != curr_path.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    return 0;
}

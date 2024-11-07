#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

int i, j, k, a, b, u, v, n, ne = 1;
int minimum, mincost = 0, cost[9][9], parent[9] = {0};

int find(int);
int uni(int, int);

int main()
{
    cout << "\n\tImplementation of Kruskal's algorithm\n";
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    cout << "\nEnter the cost adjacency matrix:\n";

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX; // Using INT_MAX instead of 999 for infinity
        }
    }

    cout << "The edges of Minimum Cost Spanning Tree are\n";

    while (ne < n)
    {
        for (i = 1, minimum = INT_MAX; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < minimum)
                {
                    minimum = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            cout << ne++ << " edge (" << a << ", " << b << ") = " << minimum << endl;
            mincost += minimum;
        }
        cost[a][b] = INT_MAX; // Mark as visited
    }
    cout << "\n\tMinimum cost = " << mincost << endl;
    return 0;
}

int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

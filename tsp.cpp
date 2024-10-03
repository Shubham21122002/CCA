#include<iostream>
using namespace std;
#define INT_MAX 999
int n = 4;
int dist[10][10] = {
    {0, 1, 2, 3},
    {1, 0, 3, 4},
    {1, 2, 0, 6},
    {2, 3, 4, 0}
};
int visited_all = (1<<n)-1;
int tsp(int mask, int pos) {
    
    if(mask==visited_all) {
        return dist[pos][0];
    }

    // Try to goto unvisited city
    int ans = INT_MAX;
    for(int city = 0 ; city < n ; city++) {
        if(mask&(1<<city) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1<<city), city);
            ans = min(newAns,ans);
        }
    }
    return ans;
}

int main() 
{
    cout<<"MST : "<<tsp(1, 0);
 return 0;
}
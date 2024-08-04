 // depth first search
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/0

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"

/*
5 5
1 2
1 3
2 4
3 5
3 4
*/
void dfs(int node, vector<bool> &visited, vector<vector<int>> graph) // O(n)+O(2e) Σ degrees
{
    visited[node] = true;
    cout << node << " ";
    // traveling all neighbors
    for (auto i : graph[node])
    {
        if (!visited[i]) // false-not visited
        {
            dfs(i, visited, graph);
        }
    }
}

void AdjList()
{
    int n, e; // no. of nodes, edges
    cin >> n >> e;
    vector<vector<int>> graph(n + 1);

    // Storing graph using adjacency list
    for (int i = 0; i < e; i++)
    {
        int u, v; // u -> v
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected graph
    }
    vector<bool> visited(n, false);
    dfs(1, visited, graph);
}

int32_t main()
{
    AdjList();
    return 0;
}
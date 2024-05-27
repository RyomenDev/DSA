// level order traversal
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/0

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
void bfs(vector<vector<int>> graph) // O(n)+O(2e)
{
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto i : graph[node])
        {
            if (!visited[i]) // not visited
            {
                q.push(i);
                visited[i] = true;
            }
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
    bfs(graph);
}

int32_t main()
{
    AdjList();
    return 0;
}
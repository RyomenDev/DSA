#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl "\n"

// storing graph O(n) by adjacency matrix & space O(n^2)
void AdjMatrix()
{
    int n, e; // no.of nodes, edge
    cin >> n >> e;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < e; i++)
    {
        int u, v; // u->v
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected graph
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
/*
5 5
1 2
1 3
2 4
3 5
3 4
*/
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

    for (int i = 1; i <= n; i++)
    {
        cout << "head " << i << ": ";
        for (auto j : graph[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
/*
5 5
1 2 2
1 3 3
2 4 1
3 5 2
3 4 4
*/
// weighted AdjList graph
void weightedAdjList()
{
    int n, e; // no. of nodes, edges
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n + 1);

    // Storing graph using adjacency list
    for (int i = 0; i < e; i++)
    {
        int u, v, w; // u -> v
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected graph
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "head " << i << ": ";
        for (auto j : graph[i])
        {
            cout << j.first << ":" << j.second << " ";
        }
        cout << endl;
    }
}

int32_t main()
{

    // AdjMatrix();
    // AdjList();
    weightedAdjList();

    return 0;
}
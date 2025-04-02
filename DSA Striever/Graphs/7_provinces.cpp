 // https://www.geeksforgeeks.org/problems/number-of-provinces/1
// https://leetcode.com/problems/count-the-number-of-complete-components/description/
// Number of Provinces
// A province is a group of directly or indirectly connected cities and no other cities outside of the group

class Solution {
    void dfs(int idx, vector<int>& vis, vector<vector<int>>& grid, int& nodes, int& edges) {
        if (vis[idx]) return;
        vis[idx] = 1;
        nodes++; // Counting nodes in this component
        edges += grid[idx].size(); // Counting edges (will be divided by 2 later)

        for (auto i : grid[idx])
            if (!vis[i]) dfs(i, vis, grid, nodes, edges);
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> grid(n);
        for (auto& i : edges) {
            int a = i[0], b = i[1];
            grid[a].push_back(b);
            grid[b].push_back(a);
        }

        vector<int> vis(n, 0);
        int completeCount = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0, edges = 0;
                dfs(i, vis, grid, nodes, edges);
                // Each edge is counted twice in an undirected graph
                edges /= 2;
                // A complete graph with 'nodes' vertices should have 'nodes * (nodes - 1) / 2' edges
                if (edges == (nodes * (nodes - 1)) / 2)
                    completeCount++;
            }
        }

        return completeCount;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<vector<int>> graph, vector<bool> &visited) // O(N)+O(v+2e)
    {
        visited[node] = true;
        for (auto it : graph[node])
        {
            if (!visited[it])
            {
                dfs(it, graph, visited);
            }
        }
    }

    // Alternate : by bfs
    void bfs(int node, vector<vector<int>> graph, vector<bool> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            // printing / storing
            for (auto it : graph[temp])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // to adjList
        vector<vector<int>> graph(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                // dfs(i, graph, visited);
                bfs(i, graph, visited);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends
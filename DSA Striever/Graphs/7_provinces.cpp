// https://www.geeksforgeeks.org/problems/number-of-provinces/1
// Number of Provinces
// A province is a group of directly or indirectly connected cities and no other cities outside of the group

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, vector<vector<int>> graph, vector<bool> &visited)
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
// https://www.geeksforgeeks.org/problems/topological-sort/1
//^ Khans's Algorithm
    /*
    & 1: insert all nodes with inDegree 0
    & 2: from those node move to others and decrease their inDegree
    & 3: if their inDegree become 0 push to result else push in queue
    % inDegree ensures no node visited extra times
    */
   /*
   ^ inDegree - number of incoming edges
   */
// ! only in DAG - directed Acyclic graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution // sc:(v) tc(v+e)
{
    vector<int> bfs(int V, vector<int> adj[])
    {
        vector<int> res;
        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++)
            for (int nbr : adj[i])
                inDegree[nbr]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int nbr : adj[curr])
            {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return res;
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        return bfs(V, adj);
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int>& res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends
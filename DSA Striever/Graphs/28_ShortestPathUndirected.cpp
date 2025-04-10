
// Shortest Path in Undirected

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
public:
  // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int>ans(V, INT_MAX);
        vector<int>vis(V, 0);
        queue<pair<int, int>>q;
        q.push({src,0});
        while (!q.empty()) {
            auto it = q.front();
            int node = it.first;
            int wt = it.second;
            vis[node] = 1;
            ans[node] = min(wt, ans[node]);
            q.pop();
            for (auto i : adj[node]) {
                if (!vis[i]) {
                    q.push({i,wt + 1});
                }
            }
        }
        for (int i = 0; i < V; i++)
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        return ans;
    }
};

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> ans(V, -1);
        queue<int> q;
        ans[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                // If not visited yet
                if (ans[neighbor] == -1) {
                    ans[neighbor] = ans[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }
};


// Detect cycle in a directed graph using DFS

// ! BFS logic will not work-> khan's algo and topological sort is used

class Solution {
    vector<int>vis;
    vector<int>pathVis;
    bool dfs(int node, vector<vector<int>>graph) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto i : graph[node]) {
            if (!vis[i]) {
                if (dfs(i, graph))
                    return true;
            }
            else if (pathVis[i])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>graph(V);
        for (auto i : edges) {
            int a = i[0], b = i[1];
            graph[a].push_back(b);
        }
        vis = vector<int>(V, 0);
        pathVis = vector<int>(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                if (dfs(i, graph))
                    return true;
        }
        return false;
    }
};
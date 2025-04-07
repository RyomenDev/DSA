// Find Eventual Safe States - DFS

// https://leetcode.com/problems/find-eventual-safe-states/description/

// https://www.geeksforgeeks.org/problems/eventual-safe-states/1

/*
! find terminal nodes (target)
! detect cycle -  any node part of or connected (incoming edges) to cycle is not safe node - leads to cycle 
*/

class Solution {
    vector<int>safeNodes;
    vector<int>vis;
    vector<int>pathVis;
    // bool dfs(int node, vector<vector<int>>graph) {
    bool dfs(int node, vector<int> graph[]) {
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
        safeNodes[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // vector<vector<int>>graph(V);
        // for (auto i : adj) {
        //     int a = i[0], b = i[1];
        //     graph[a].push_back(b);
        // }
        vis = vector<int>(V, 0);
        safeNodes = vector<int>(V, 0);
        pathVis = vector<int>(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, adj);
        }
        vector<int>ans;
        for (int i = 0; i < V; i++)
            if (safeNodes[i]) ans.push_back(i);
        return ans;;
    }
};
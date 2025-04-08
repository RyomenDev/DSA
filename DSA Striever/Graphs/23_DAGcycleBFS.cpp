// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Detect cycle in a directed graph using DFS

class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int>ans;
        vector<int>inDegree(V, 0);
        vector<vector<int>>edges(V);
        for (auto i : adj)
            edges[i[0]].push_back(i[1]);

        for (auto i : edges)
            for (auto j : i)
                inDegree[j]++;
        queue<int>q;
        for (int i = 0; i < V; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto i : edges[curr]) {
                inDegree[i]--;
                if (!inDegree[i])
                    q.push(i);
            }
        }
        return ans;
    }
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>vec = topoSort(V, edges);
        int nodes = vec.size();
        return (nodes != V);
    }
};
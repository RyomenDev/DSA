
// Find Eventual Safe States

// https://leetcode.com/problems/find-eventual-safe-states/description/

// https://www.geeksforgeeks.org/problems/eventual-safe-states/1

class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> inDegree(V, 0);

        for (auto& i : edges)
            for (auto& j : i)
                inDegree[j]++;

        queue<int> q;
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>edges(V);
        for (int i = 0; i < V; i++)
            for (auto j : graph[i])
                edges[j].push_back(i);
        // vector<int> vec = topoSort(V, graph);
        vector<int> vec = topoSort(V, edges);
        int nodes = vec.size();
        // return (nodes == V);
        sort(vec.begin(), vec.end());
        // for (auto i : vec)
        //     cout << i << " ";
        return vec;
    }
};
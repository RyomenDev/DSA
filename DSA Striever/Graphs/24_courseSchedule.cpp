// course-schedule
// Prerequisite Tasks

// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1
// https://leetcode.com/problems/course-schedule/description/
// https://www.geeksforgeeks.org/problems/course-schedule/1

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
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) {
        vector<vector<int>> graph(V);
        for (auto i : prerequisites) {
            int a = i[0];
            int b = i[1];
            graph[a].push_back(b);
        }
        vector<int> vec = topoSort(V, graph);
        int nodes = vec.size();
        // return (nodes == V);
        reverse(vec.begin(), vec.end());
        // for(auto i : vec)
        //     cout<<i<<" ";
        if (nodes == V)
            return vec;
        else
            return {};
    }
};
// Bipartite Graph

// https://leetcode.com/problems/is-graph-bipartite/description/
// https://www.geeksforgeeks.org/problems/bipartite-graph/1

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // if (!graph.size() || !graph[0].size())
        //     return true;
        int n = graph.size();
        map<int, char> mp;
        for (int start = 0; start < n; start++) {
            if (mp.find(start) != mp.end())
                continue;
            queue<int> q;
            q.push(start);
            mp[start] = '0';
            // mp[0] = 0;

            while (!q.empty()) {
                int currNode = q.front();
                q.pop();
                int color = mp[currNode] == '0' ? '1' : '0';
                // int color = mp[currNode] == 0 ? 1 : 0;
                for (auto i : graph[currNode]) {
                    if (mp.find(i) == mp.end()) {
                        mp[i] = color;
                        q.push(i);
                    }
                    else if (mp[i] != color) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
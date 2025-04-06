// Bipartite Graph

// https://leetcode.com/problems/is-graph-bipartite/description/
// https://www.geeksforgeeks.org/problems/bipartite-graph/1

class Solution {
    vector<int> color; // -1 means uncolored, 0 & 1 are two colors
    bool dfs(int node, int currColor, vector<vector<int>>& graph) {
        color[node] = currColor;
        for (auto neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - currColor, graph))
                    return false;
            }
            else if (color[neighbor] == color[node])
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int>(n, -1);
        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                if (!dfs(start, 0, graph)) return false;
            }
        }
        return true;
        // int n = graph.size();
        // color = vector<int>(n, -1);
        // for (int start = 0; start < n; start++) {
        //     if (color[start] != -1)
        //         continue; // Already colored in a previous BFS

        //     queue<int> q;
        //     q.push(start);
        //     color[start] = 0; // Start coloring with 0

        //     while (!q.empty()) {
        //         int node = q.front();
        //         q.pop();

        //         for (int neighbor : graph[node]) {
        //             if (color[neighbor] ==
        //                 -1) { // If uncolored, assign opposite color
        //                 color[neighbor] = 1 - color[node];
        //                 q.push(neighbor);
        //             } else if (color[neighbor] ==
        //                        color[node]) { // Conflict found
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // return true;
    }
};


// Shortest path in Directed Acyclic Graph
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
    stack<int>st;
    vector<int>vis;
    void topoSort(int V, vector<vector<pair<int, int>>>& graph) {
        vis[V] = 1;
        for (auto i : graph[V])
            if (!vis[i.first])
                topoSort(i.first, graph);
        st.push(V);
    }
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>graph(V);
        vis = vector<int>(V, 0);
        for (auto i : edges) {
            int v1 = i[0], v2 = i[1], w = i[2];
            graph[v1].push_back({v2,w});
        }
        topoSort(0, graph);
        // for(int i = 0; i < V ;i++)
        //     if(!vis[i])
        //         topoSort(i,graph);

        vector<int>dist(V, INT_MAX);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (dist[node] != INT_MAX) {
                for (auto it : graph[node]) {
                    dist[it.first] = min(dist[it.first], dist[node] + it.second);
                    // int v = it.first;
                    // int wt = it.second;
                    // if (dist[node] + wt < dist[v])
                    //     dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < V; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        return dist;
    }
};
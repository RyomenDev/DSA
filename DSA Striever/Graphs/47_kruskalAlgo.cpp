// Kruskal's Algorithm 
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?
// https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution
{
    vector<int> rank, parent, size;

    void DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // ~ path compression
    }


    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    // void unionByRank(int u, int v) {
    //     int ulp_u = findUPar(u);
    //     int ulp_v = findUPar(v);
    //     if (ulp_u == ulp_v) return;
    //     if (rank[ulp_u] < rank[ulp_v]) {
    //         parent[ulp_u] = ulp_v;
    //     }
    //     else if (rank[ulp_u] > rank[ulp_v]) {
    //         parent[ulp_v] = ulp_u;
    //     }
    //     else { // ! attaching
    //         parent[ulp_v] = ulp_u;
    //         rank[ulp_u]++;
    //     }
    // }


    struct Edge {
        int u, v, weight;
        bool operator<(Edge const& other) {
            return weight < other.weight;
        }
    };

    int Kruskal(int V, vector<Edge>& edges) {
        parent.resize(V);
        size.resize(V);
        DisjointSet(V);

        sort(edges.begin(), edges.end());

        int cost = 0;
        vector<Edge> result;
        for (Edge e : edges)
            if (findUPar(e.u) != findUPar(e.v)) {
                cost += e.weight;
                result.push_back(e);
                // unionBySize(e.u, e.v);
                unionByRank(e.u, e.v);
            }

        return cost;
    }

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj [ ]) {
        vector<Edge> edges;
        for (int i = 0; i < V; ++i)
            for (auto it : adj[i])
                edges.push_back({i, it[0], it[1]});
        return Kruskal(V, edges);
    }
};

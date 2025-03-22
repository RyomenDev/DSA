
// All Nodes Distance K in Binary Tree

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

// https://www.geeksforgeeks.org/problems/k-distance-from-root/1

class Solution {
    unordered_map<TreeNode*, int> visited;
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    void solve(TreeNode* node, int k, vector<int>& ans) {
        // if (visited[node]) return;
        if (k == 0) {
            ans.push_back(node->val);
            return;
        }
        visited[node] = 1;
        for (auto i : graph[node])
            if (visited[i] != 1)
                solve(i, k - 1, ans);
    }
    void buildGraph(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            buildGraph(root->left);
        }
        if (root->right) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            buildGraph(root->right);
        }
    };

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        visited.clear();
        graph.clear();
        buildGraph(root);

        vector<int> ans;
        solve(target, k, ans);
        return ans;
    }
};
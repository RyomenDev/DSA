
// Amount of Time for Binary Tree to Be Infected

// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// https://www.geeksforgeeks.org/problems/burning-tree/1

class Solution {
    TreeNode* startNode;
    unordered_map<TreeNode*, int> infected;
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    void buildGraph(TreeNode* root, int start) {
        if (!root)
            return;
        if (root->val == start)
            startNode = root;
        if (root->left) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            buildGraph(root->left, start);
        }
        if (root->right) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            buildGraph(root->right, start);
        }
    };
    void solve(TreeNode* node, int time, int& ans) {
        // if (infected[node]) return;
        if (!node)
            return;
        ans = max(ans, time);
        infected[node] = 1;
        for (auto i : graph[node])
            if (infected[i] != 1)
                solve(i, time + 1, ans);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        infected.clear();
        graph.clear();
        buildGraph(root, start);

        int ans;
        solve(startNode, 0, ans);
        return ans;
    }
};
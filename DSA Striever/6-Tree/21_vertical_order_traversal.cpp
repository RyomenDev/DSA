// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        map<int, map<int, multiset<int>>> nodes;  // {col -> {row -> {values}}}
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {col, row}}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int col = pos.first, row = pos.second;
            nodes[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }
        // for (auto [col, rowMap] : nodes) {
        //     vector<int> colVals;
        //     for (auto [row, vals] : rowMap)
        //         colVals.insert(colVals.end(), vals.begin(), vals.end());
        //     ans.push_back(colVals);
        // }
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            vector<int> colVals;
            for (auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
                colVals.insert(colVals.end(), jt->second.begin(),
                               jt->second.end());
            }
            ans.push_back(colVals);
        }
        return ans;
    }
};

// 

//
 
// 

class Solution {
    map<int, map<int, multiset<int>>> nodes;  // {col -> {row -> {values}}}
    void inOrder(TreeNode* root, int col, int row) {
        if (!root) return;
        inOrder(root->left, col - 1, row + 1);
        nodes[col][row].insert(root->val);
        inOrder(root->right, col + 1, row + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        inOrder(root, 0, 0);
        for (auto [col, rowMap] : nodes) {
            vector<int> colVals;
            for (auto [row, vals] : rowMap)
                colVals.insert(colVals.end(), vals.begin(), vals.end());
            ans.push_back(colVals);
        }
        nodes.clear();
        return ans;
    }
};
// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

// https://leetcode.com/problems/binary-tree-paths/description/

class Solution {
    vector<string> ans;
    void solve(TreeNode* root, string str) {
        if (!root) return;
        if (!str.empty()) str += "->";
        str += to_string(root->val);
        if (!root->left && !root->right) { // If it's a leaf node, add the path to the result
            ans.push_back(str);
            return;
        }
        solve(root->left, str);
        solve(root->right, str);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string str = "";
        solve(root, str);
        return ans;
    }
};
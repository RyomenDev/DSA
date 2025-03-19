

// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
    vector<int> ans;
    void solve(TreeNode* root, int level) { // root right left (not preOrder)
        if (!root) return;
        int n = ans.size();
        if (level == n) ans.push_back(root->val);
        solve(root->right, level + 1);
        solve(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // if (!root) return ans;
        // queue<TreeNode*> q;
        // q.push(root);
        // while (!q.empty()) {
        //     int n = q.size();
        //     while (n--) {
        //         TreeNode* curr = q.front();
        //         q.pop();
        //         if (n == 0) ans.push_back(curr->val);
        //         if (curr->left) q.push(curr->left);
        //         if (curr->right) q.push(curr->right);
        //     }
        // }
        solve(root, 0);
        return ans;
    }
};
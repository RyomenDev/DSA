// https://www.geeksforgeeks.org/problems/symmetric-tree/1

// https://leetcode.com/problems/symmetric-tree/

class Solution {
    bool solve(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2 || (root1->val != root2->val))
            return false;
        return solve(root1->left, root2->right) &&
            solve(root1->right, root2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return true;
        return solve(root->left, root->right);
    }
};
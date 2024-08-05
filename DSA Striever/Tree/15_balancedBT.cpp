// https://leetcode.com/problems/balanced-binary-tree/

class Solution {
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = height(root->left);
        if (left == -1)
            return -1;
        int right = height(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
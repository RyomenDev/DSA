

// Lowest Common Ancestor in Binary Tree

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode* a = lowestCommonAncestor(root->left, p, q);
        TreeNode* b = lowestCommonAncestor(root->right, p, q);
        if (a == NULL) return b;
        if (b == NULL) return a;
        return root;
    }
};
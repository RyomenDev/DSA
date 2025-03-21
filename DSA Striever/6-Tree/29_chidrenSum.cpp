// Root Equals Sum of Children

// https://leetcode.com/problems/root-equals-sum-of-children/description/
// https://www.geeksforgeeks.org/problems/children-sum-parent/1

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;
        if (root->val != leftVal + rightVal) return false;
        return checkTree(root->left) && checkTree(root->right);
    }
};


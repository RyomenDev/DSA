// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

class Solution {
    int ans = INT_MIN;
    unordered_map<TreeNode*, int> dp;
    int solve(TreeNode* root) {
        if (!root)
            return 0;
        if (dp.find(root) != dp.end())
            return dp[root];
        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));
        ans = max(ans, root->val + left + right);
        return dp[root] = root->val + max(left, right);
        ;
    }

public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};

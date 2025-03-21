// Maximum Width of Binary Tree

// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

// https://www.geeksforgeeks.org/problems/maximum-width-of-tree/1

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            long long firstPos = q.front().second;
            long long lastPos = q.back().second;
            long long len = lastPos - firstPos + 1;
            ans = max(ans, int(len));
            while (n--) {
                TreeNode* front = q.front().first;
                long long normalizePos = q.front().second - firstPos;
                q.pop();
                if (front->left)
                    q.push({front->left, 2 * normalizePos + 1});
                if (front->right)
                    q.push({front->right, 2 * normalizePos + 2});
            }
        }
        return ans;
    }
};
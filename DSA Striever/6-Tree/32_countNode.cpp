// Count Number of Nodes in a Binary Tree

// https://www.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1

// https://leetcode.com/problems/count-complete-tree-nodes/description/

class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            ans++;
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return ans;
    }
};
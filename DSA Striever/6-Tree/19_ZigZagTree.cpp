// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> vec;
            int n = q.size();
            while (n--) {
                TreeNode* tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            if (level % 2 != 0)
                reverse(vec.begin(), vec.end());
            ans.push_back(vec);
            level++;
        }
        return ans;
    }
};
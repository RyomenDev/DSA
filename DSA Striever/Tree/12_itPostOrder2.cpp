// https://leetcode.com/problems/binary-tree-postorder-traversal/description/?

// iterative postOrder

// left right  root

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> st1, st2;
        TreeNode* node = root;
        st1.push(node);
        while (!st1.empty()) {
            node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left)
                st1.push(node->left);
            if (node->right)
                st1.push(node->right);
        }
        while (!st2.empty()) {
            node = st2.top();
            st2.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
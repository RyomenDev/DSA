// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// iterative inOrder

// left root  right 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;
        while (1) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};
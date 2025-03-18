// https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

// https://leetcode.com/problems/same-tree/description/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution {
    void inorder(vector<int>& v, TreeNode* root) {
        if (!root) {
            v.push_back(NULL);
            return;
        }
        inorder(v, root->right);
        v.push_back(root->val);
        inorder(v, root->left);
    }
    void postorder(vector<int>& v, TreeNode* root) {
        if (!root) {
            v.push_back(NULL);
            return;
        }
        postorder(v, root->right);
        postorder(v, root->left);
        v.push_back(root->val);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pi, qi, pp, qp;
        inorder(pi, p);
        inorder(qi, q);
        postorder(pp, p);
        postorder(qp, q);
        return (pi == qi && pp == qp);
    }
};
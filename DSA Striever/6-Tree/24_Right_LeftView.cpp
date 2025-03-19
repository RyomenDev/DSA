// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    vector<int> leftView(Node* root) {
        // code here
        vector<int> ans;
        if (!root) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int idx = n;
            while (idx--) {
                Node* curr = q.front();
                q.pop();
                // if (idx == n - 1) ans.push_back(curr->data);
                if (n == 0) ans.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

class Solution {
    vector<int> ans;
    void solve(Node* root, int level) { // root left right 
        if (!root) return;
        int n = ans.size();
        if (level == n) ans.push_back(root->data);
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
public:
    vector<int> leftView(Node* root) {
        // vector<int> ans;
        // code here
        // if (!root) return ans;
        // queue<Node*> q;
        // q.push(root);
        // while (!q.empty()) {
        //     int n = q.size();
        //     int idx=n;
        //     while (idx--) {
        //         Node* curr = q.front();
        //         q.pop();
        //         if (idx == n-1) ans.push_back(curr->data);
        //         if (curr->left) q.push(curr->left);
        //         if (curr->right) q.push(curr->right);
        //     }
        // }
        // return ans;
        solve(root, 0);
        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution {
public:
  // Function to return a list of nodes visible from the top view
  // from left to right in Binary Tree.
    vector<int> topView(Node* root) {
        // code here
        vector<int> ans;
        if (!root) return ans;
        map<int, int>mp;
        queue<pair<Node*, int>>q; // {node, horizontalDistance} node , rowNum
        q.push({root,0});
        while (!q.empty()) {
            Node* curr = q.front().first;
            int rowNum = q.front().second; // Horizontal distance
            q.pop();
            if (mp.find(rowNum) == mp.end()) mp[rowNum] = curr->data;
            if (curr->left) q.push({curr->left,rowNum - 1});
            if (curr->right) q.push({curr->right,rowNum + 1});
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
            ans.push_back(it->second);
        mp.clear();
        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class Solution {
    vector<int> ans;
    void leftWithoutLeaf(Node* root) {
        if (!root || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        if (root->left) leftWithoutLeaf(root->left);
        else leftWithoutLeaf(root->right);
    }
    void LeafNodes(Node* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        LeafNodes(root->left);
        LeafNodes(root->right);
    }
    void rightWithoutLeaf(Node* root) {
        if (!root || (!root->left && !root->right)) return;
        // ans.push_back(root->data);
        if (root->right) rightWithoutLeaf(root->right);
        else rightWithoutLeaf(root->left);
        ans.push_back(root->data); //  // Collect in reverse order
    }
public:
    vector<int> boundaryTraversal(Node* root) {
        // code here
        if (!root)
            return ans;
        ans.push_back(root->data);
        if (root->left) leftWithoutLeaf(root->left);
        LeafNodes(root->left);
        LeafNodes(root->right);
        if (root->right) rightWithoutLeaf(root->right);
        return ans;
    }
};
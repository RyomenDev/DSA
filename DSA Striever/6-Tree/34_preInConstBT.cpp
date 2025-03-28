// https://www.geeksforgeeks.org/problems/construct-tree-1/1
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// ! Construct a Binary Tree from Preorder and InOrder Traversal

// ^ unique elements

class Solution {
    TreeNode* solve(int preStart, int preEnd, vector<int>& preOrder, int inStart,
                int inEnd, vector<int>& inOrder, map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preOrder[preStart]);
        int inRoot = mp[root->val]; 
        int numsLeft = inRoot - inStart;

        root->left = solve(preStart + 1, preStart + numsLeft, preOrder, inStart,
                           inRoot - 1, inOrder, mp);
        root->right = solve(preStart + numsLeft + 1, preEnd, preOrder,
                            inRoot + 1, inEnd, inOrder, mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            // Map value to the first occurrence index in inorder traversal
            if (mp.find(inorder[i]) == mp.end()) {
                mp[inorder[i]] = i;
            }
        }
        return solve(0, n - 1, preorder, 0, n - 1, inorder, mp);
    }
};

//

//


// ^ repeating elements

Node is as follows :
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
    Node* solve(int preStart, int preEnd, int preOrder[],
                int inStart, int inEnd, int inOrder[],
                map<int, vector<int>>& mp, map<int, int>& used) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        int rootValue = preOrder[preStart];
        Node* root = new Node(rootValue);
        // Find the correct index in the inorder array
        int inRoot = mp[rootValue][used[rootValue]];
        used[rootValue]++; // Increment the count of usage

        int numsLeft = inRoot - inStart;

        root->left = solve(preStart + 1, preStart + numsLeft,
                            preOrder, inStart, inRoot - 1, inOrder, mp, used);
        root->right = solve(preStart + numsLeft + 1, preEnd,
                            preOrder, inRoot + 1, inEnd, inOrder, mp, used);
        return root;
    }
public:
    Node* buildTree(int in[], int pre[], int n) {
        map<int, vector<int>> mp;
        map<int, int> used;
        for (int i = 0; i < n; i++) {
            mp[in[i]].push_back(i);
            used[in[i]] = 0; // Initialize usage count to 0
        }
        return solve(0, n - 1, pre, 0, n - 1, in, mp, used);
    }
};


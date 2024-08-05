// https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// ! Construct the Binary Tree from Postorder and Inorder Traversal

// ^ Unique values
/*
class Solution {
    TreeNode* solve(int postStart, int postEnd, vector<int>& postOrder,
                    int inStart, int inEnd, vector<int>& inOrder,
                    map<int, int>& mp) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postOrder[postEnd]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = solve(postStart, postStart + numsLeft - 1, postOrder,
                           inStart, inRoot - 1, inOrder, mp);
        root->right = solve(postStart + numsLeft, postEnd - 1, postOrder,
                            inRoot + 1, inEnd, inOrder, mp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            // Map value to the first occurrence index in inorder traversal
            if (mp.find(inorder[i]) == mp.end()) {
                mp[inorder[i]] = i;
            }
        }
        return solve(0, n - 1, postorder, 0, n - 1, inorder, mp);
    }
};
*/

// ^ Unique values
//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    Node* solve(int postStart, int postEnd, vector<int>& postOrder,
                   int inStart, int inEnd, vector<int>& inOrder,
                   map<int, int>& mp) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        Node* root = new Node(postOrder[postEnd]);
        int inRoot = mp[root->data];
        int numsLeft = inRoot - inStart;

        root->left = solve(postStart, postStart + numsLeft - 1, postOrder,
                           inStart, inRoot - 1, inOrder, mp);
        root->right = solve(postStart + numsLeft, postEnd - 1, postOrder,
                            inRoot + 1, inEnd, inOrder, mp);
        return root;
    }

public:

//Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(int in[], int post[], int n) {
        // Your code here
        vector<int>inorder(in, in + n);
        vector<int>postorder(post, post + n);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            // Map value to the first occurrence index in inorder traversal
            if (mp.find(inorder[i]) == mp.end()) {
                mp[inorder[i]] = i;
            }
        }
        return solve(0, n - 1, postorder, 0, n - 1, inorder, mp);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
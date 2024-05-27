
#include <bits/stdc++.h>
using namespace std;

// creating binary tree
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Inorder
node *buildTree(node *root)
{
    // cout << "enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    // cout << "enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    // cout << "enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// level order traversal
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // print the data of node
        cout << temp->data << " ";
        // node->left , node
        if (temp->left)
            q.push(temp->left);
        // node->right
        if (temp->right)
            q.push(temp->right);
        return;
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}
// 20:10
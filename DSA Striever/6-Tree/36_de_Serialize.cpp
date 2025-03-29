
// /  Serialize and De-serialize Binary Tree 

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "NULL";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (!front) {
                ans += "NULL,";
                continue;
            }
            ans += (to_string(front->val) + ',');
            q.push(front->left);
            q.push(front->right);
        }
        while (ans.size() > 5 && ans.substr(ans.size() - 5) == "NULL,")
            ans.erase(ans.size() - 5);
        if (!ans.empty() && ans.back() == ',')
            ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        vector<string> temp;
        stringstream ss(data);
        string token;

        // Splitting the string by ','
        while (getline(ss, token, ',')) {
            temp.push_back(token);
        }

        if (temp[0] == "NULL")
            return NULL;

        // Root node
        TreeNode* root = new TreeNode(stoi(temp[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1; // Start from second element
        while (!q.empty() && i < temp.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // Process left child
            if (i < temp.size() && temp[i] != "NULL") {
                curr->left = new TreeNode(stoi(temp[i]));
                q.push(curr->left);
            }
            i++;

            // Process right child
            if (i < temp.size() && temp[i] != "NULL") {
                curr->right = new TreeNode(stoi(temp[i]));
                q.push(curr->right);
            }
            i++;
        }

        return root;
    }
};
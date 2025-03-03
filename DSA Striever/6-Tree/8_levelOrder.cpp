
// void levelOrder(TreeNode* node) {
//     queue<TreeNode*>q;
//     if (!node)
//         return;
//     q.push(node);
//     while (!q.empty()) {
//         int size = q.size();
//         while (size--) {
//             TreeNode* temp = q.front();
//             q.pop();
//             if (!node->left)
//                 q.push(node->left);
//             if (!node->right)
//                 q.push(node->right);
//             cout << node->val << " ";
//         }
//         cout << endl;
//     }
// }
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;

    if (root == nullptr) {
      return ans;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> arr;

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();
        arr.push_back(node->data);

        if (node->left != nullptr) {
          q.push(node->left);
        }

        if (node->right != nullptr) {
          q.push(node->right);
        }
      }

      ans.push_back(arr);
    }

    return ans;
  }
};

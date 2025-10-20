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
private:
  vector<vector<int>> levelOrderTraversal(TreeNode *root) {
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      vector<int> level;

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();
        level.push_back(node->data);

        if (node->left != nullptr) {
          q.push(node->left);
        }

        if (node->right != nullptr) {
          q.push(node->right);
        }
      }

      ans.push_back(level);
    }

    return ans;
  }

public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;

    if (root == nullptr) {
      return ans;
    }

    vector<vector<int>> nodes = levelOrderTraversal(root);

    for (int i = 0; i < nodes.size(); i++) {
      ans.push_back(nodes[i].back());
    }

    return ans;
  }
};

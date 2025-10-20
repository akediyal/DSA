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
  long long int levelOrderTraversal(TreeNode *root) {
    long long int max_width = 0;
    queue<pair<TreeNode *, long long int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      int n = q.size();
      long long int mn = q.front().second;
      long long int first = 0, last = 0;

      for (int i = 0; i < n; i++) {
        long long int cur_idx = q.front().second - mn;
        TreeNode *node = q.front().first;
        q.pop();

        if (i == 0) {
          first = cur_idx;
        }

        if (i == n - 1) {
          last = cur_idx;
        }

        if (node->left != nullptr) {
          q.push({node->left, (2 * cur_idx) + 1});
        }

        if (node->right != nullptr) {
          q.push({node->right, (2 * cur_idx) + 2});
        }
      }

      max_width = max(max_width, last - first + 1);
    }

    return max_width;
  }

public:
  long long int widthOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return levelOrderTraversal(root);
  }
};

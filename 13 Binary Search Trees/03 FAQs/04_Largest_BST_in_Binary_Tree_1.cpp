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
  bool isBST(TreeNode *root, long min, long max) {
    if (root == nullptr) {
      return true;
    }

    if (root->data <= min || root->data >= max) {
      return false;
    }

    bool left = isBST(root->left, min, root->data);
    bool right = isBST(root->right, root->data, max);

    return left && right;
  }

  vector<TreeNode *> levelOrderTraversal(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    vector<TreeNode *> arr;

    while (!q.empty()) {
      int n = q.size();

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (isBST(node, LONG_MIN, LONG_MAX)) {
          arr.push_back(node);
        }

        if (node->left != nullptr) {
          q.push(node->left);
        }

        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
    }

    return arr;
  }

  void countNodes(TreeNode *root, int &count) {
    if (root == nullptr) {
      return;
    }

    countNodes(root->left, count);
    count++;
    countNodes(root->right, count);
  }

public:
  int largestBST(TreeNode *root) {
    vector<TreeNode *> bst_roots = levelOrderTraversal(root);
    int ans = 0;

    for (auto &node : bst_roots) {
      int count = 0;
      countNodes(node, count);
      ans = max(ans, count);
    }

    return ans;
  }
};

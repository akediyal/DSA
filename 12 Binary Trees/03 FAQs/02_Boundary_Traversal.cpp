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
  bool isLeaf(TreeNode *node) {
    return (node->left == nullptr) && (node->right == nullptr);
  }

  void addLeftBoundary(TreeNode *node, vector<int> &ans) {
    while (node != nullptr) {
      if (!isLeaf(node)) {
        ans.push_back(node->data);
      }

      if (node->left != nullptr) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
  }

  void addLeaves(TreeNode *node, vector<int> &ans) {
    if (isLeaf(node)) {
      ans.push_back(node->data);
      return;
    }

    if (node->left != nullptr) {
      addLeaves(node->left, ans);
    }

    if (node->right != nullptr) {
      addLeaves(node->right, ans);
    }
  }

  void addRightBoundary(TreeNode *node, vector<int> &ans) {
    vector<int> arr;

    while (node != nullptr) {
      if (!isLeaf(node)) {
        arr.push_back(node->data);
      }

      if (node->right != nullptr) {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    while (!arr.empty()) {
      ans.push_back(arr.back());
      arr.pop_back();
    }
  }

public:
  vector<int> boundary(TreeNode *root) {
    vector<int> ans;

    if (root == nullptr) {
      return ans;
    }

    if (!isLeaf(root)) {
      ans.push_back(root->data);
    }

    addLeftBoundary(root->left, ans);
    addLeaves(root, ans);
    addRightBoundary(root->right, ans);

    return ans;
  }
};

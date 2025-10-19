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
  bool helperFunc(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }

    if (left == nullptr || right == nullptr) {
      return false;
    }

    if (left->data != right->data) {
      return false;
    }

    return helperFunc(left->left, right->right) &&
           helperFunc(left->right, right->left);
  }

public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return helperFunc(root->left, root->right);
  }
};

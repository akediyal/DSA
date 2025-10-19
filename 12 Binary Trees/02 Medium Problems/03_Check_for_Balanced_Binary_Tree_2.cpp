/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
private:
  int height(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return 1 + max(height(root->left), height(root->right));
  }

public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    if (abs(left_height - right_height) > 1) {
      return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
  }
};

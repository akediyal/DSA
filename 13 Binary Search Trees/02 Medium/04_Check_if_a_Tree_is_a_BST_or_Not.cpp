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
  bool helperFunc(TreeNode *root, long min, long max) {
    if (root == nullptr) {
      return true;
    }

    if (root->data <= min || root->data >= max) {
      return false;
    }

    bool left = helperFunc(root->left, min, root->data);
    bool right = helperFunc(root->right, root->data, max);

    return left && right;
  }

public:
  bool isBST(TreeNode *root) { return helperFunc(root, LONG_MIN, LONG_MAX); }
};

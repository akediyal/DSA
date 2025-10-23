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
  void helperFunc(TreeNode *&root, int val) {
    if (root == nullptr) {
      root = new TreeNode(val);
      return;
    }

    if (root->data > val) {
      helperFunc(root->left, val);
    } else {
      helperFunc(root->right, val);
    }
  }

public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    helperFunc(root, val);
    return root;
  }
};

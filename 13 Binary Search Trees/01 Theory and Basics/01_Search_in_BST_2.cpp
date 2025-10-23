/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
private:
  TreeNode *helperFunc(TreeNode *root, int val) {
    if (root == nullptr || root->data == val) {
      return root;
    }

    if (root->data > val) {
      return helperFunc(root->left, val);
    } else {
      return helperFunc(root->right, val);
    }
  }

public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return nullptr;
    }

    return helperFunc(root, val);
  }
};

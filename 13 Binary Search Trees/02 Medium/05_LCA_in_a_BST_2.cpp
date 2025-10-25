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
  TreeNode *helperFunc(TreeNode *root, int p, int q) {
    if (root == nullptr || root->data == p || root->data == q) {
      return root;
    }

    TreeNode *left = helperFunc(root->left, p, q);
    TreeNode *right = helperFunc(root->right, p, q);

    if (left && right) {
      return root;
    }

    return (left == nullptr) ? right : left;
  }

public:
  TreeNode *lca(TreeNode *root, int p, int q) { return helperFunc(root, p, q); }
};

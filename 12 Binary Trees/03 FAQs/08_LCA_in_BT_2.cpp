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
  TreeNode *helperFunc(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }

    TreeNode *left = helperFunc(root->left, p, q);
    TreeNode *right = helperFunc(root->right, p, q);

    if (left == nullptr) {
      return right;
    } else if (right == nullptr) {
      return left;
    } else {
      return root;
    }
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *ans = helperFunc(root, p, q);
    return ans;
  }
};

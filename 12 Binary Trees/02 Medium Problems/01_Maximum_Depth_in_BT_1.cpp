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
  int helperFunc(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    int left = helperFunc(node->left);
    int right = helperFunc(node->right);

    return 1 + max(left, right);
  }

public:
  int maxDepth(TreeNode *root) {
    int ans = helperFunc(root);
    return ans;
  }
};

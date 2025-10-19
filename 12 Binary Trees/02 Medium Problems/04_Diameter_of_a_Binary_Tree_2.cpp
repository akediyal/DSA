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
  int height(TreeNode *node, int &diameter) {
    if (node == nullptr) {
      return 0;
    }

    int left_height = height(node->left, diameter);
    int right_height = height(node->right, diameter);

    diameter = max(diameter, left_height + right_height);

    return 1 + max(left_height, right_height);
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
  }
};

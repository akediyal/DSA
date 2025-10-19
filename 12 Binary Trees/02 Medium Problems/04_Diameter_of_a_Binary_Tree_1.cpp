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
  int height(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    return 1 + max(height(node->left), height(node->right));
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    int current_diameter = left_height + right_height;

    int left_diameter = diameterOfBinaryTree(root->left);
    int right_diameter = diameterOfBinaryTree(root->right);

    return max(current_diameter, max(left_diameter, right_diameter));
  }
};

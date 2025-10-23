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
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }

    TreeNode *node = root;

    while (true) {
      if (node->data < val) {
        if (node->right != nullptr) {
          node = node->right;
        } else {
          node->right = new TreeNode(val);
          break;
        }
      }

      else {
        if (node->left != nullptr) {
          node = node->left;
        } else {
          node->left = new TreeNode(val);
          break;
        }
      }
    }

    return root;
  }
};

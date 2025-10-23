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
  vector<int> getInorder(TreeNode *root) {
    vector<int> inorder;
    TreeNode *node = root;

    while (node != nullptr) {
      if (node->left == nullptr) {
        inorder.push_back(node->data);
        node = node->right;
      }

      else {
        TreeNode *prev = node->left;

        while (prev->right != nullptr && prev->right != node) {
          prev = prev->right;
        }

        if (prev->right == nullptr) {
          prev->right = node;
          node = node->left;
        } else {
          prev->right = nullptr;
          inorder.push_back(node->data);
          node = node->right;
        }
      }
    }

    return inorder;
  }
};

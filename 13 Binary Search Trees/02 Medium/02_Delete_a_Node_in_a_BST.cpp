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
  TreeNode *findLastRight(TreeNode *root) {
    if (root->right == nullptr) {
      return root;
    }

    return findLastRight(root->right);
  }

  TreeNode *helperFunc(TreeNode *root) {
    if (root->left == nullptr) {
      return root->right;
    }

    if (root->right == nullptr) {
      return root->left;
    }

    TreeNode *right_child = root->right;
    TreeNode *last_right_child_left = findLastRight(root->left);
    last_right_child_left->right = right_child;

    return root->left;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) {
      return nullptr;
    }

    if (root->data == key) {
      return helperFunc(root);
    }

    TreeNode *node = root;

    while (node != nullptr) {
      if (node->data > key) {
        if (node->left != nullptr && node->left->data == key) {
          node->left = helperFunc(node->left);
          break;
        } else {
          node = node->left;
        }
      }

      else {
        if (node->right != nullptr && node->right->data == key) {
          node->right = helperFunc(node->right);
          break;
        } else {
          node = node->right;
        }
      }
    }

    return root;
  }
};

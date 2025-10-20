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
  int findLeftHeight(TreeNode *root) {
    int height = 0;

    while (root != nullptr) {
      height++;
      root = root->left;
    }

    return height;
  }

  int findRightHeight(TreeNode *root) {
    int height = 0;

    while (root != nullptr) {
      height++;
      root = root->right;
    }

    return height;
  }

  int helperFunc(TreeNode *root) {
    int left_height = findLeftHeight(root);
    int right_height = findRightHeight(root);

    if (left_height == right_height) {
      return (1 << left_height) - 1;
    }

    return 1 + helperFunc(root->left) + helperFunc(root->right);
  }

public:
  int countNodes(TreeNode *root) {
    int ans = 0;

    if (root == nullptr) {
      return ans;
    }

    ans = helperFunc(root);

    return ans;
  }
};

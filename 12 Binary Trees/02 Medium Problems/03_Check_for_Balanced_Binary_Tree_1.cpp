/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
private:
  int dfsHeight(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int left_height = dfsHeight(root->left);

    if (left_height == -1) {
      return -1;
    }

    int right_height = dfsHeight(root->right);

    if (right_height == -1) {
      return -1;
    }

    if (abs(right_height - left_height) > 1) {
      return -1;
    }

    return 1 + max(left_height, right_height);
  }

public:
  bool isBalanced(TreeNode *root) {
    int ans = dfsHeight(root);
    return ans != -1;
  }
};

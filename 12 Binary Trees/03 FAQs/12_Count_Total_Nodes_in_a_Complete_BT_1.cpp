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
  void preorderTraversal(TreeNode *root, int &count) {
    if (root == nullptr) {
      return;
    }

    count++;
    preorderTraversal(root->left, count);
    preorderTraversal(root->right, count);
  }

public:
  int countNodes(TreeNode *root) {
    int count = 0;

    if (root == nullptr) {
      return count;
    }

    preorderTraversal(root, count);

    return count;
  }
};

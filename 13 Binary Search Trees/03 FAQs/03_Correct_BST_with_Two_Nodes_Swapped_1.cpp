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
  void inorderTraversal(TreeNode *root, vector<int> &inorder) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
  }

  void helperFunc(TreeNode *root, vector<int> &inorder, int &idx) {
    if (root == nullptr) {
      return;
    }

    helperFunc(root->left, inorder, idx);

    if (root->data != inorder[idx]) {
      root->data = inorder[idx];
    }

    idx++;

    helperFunc(root->right, inorder, idx);
  }

public:
  void recoverTree(TreeNode *root) {
    vector<int> inorder;

    inorderTraversal(root, inorder);
    sort(inorder.begin(), inorder.end());

    int idx = 0;
    helperFunc(root, inorder, idx);
  }
};

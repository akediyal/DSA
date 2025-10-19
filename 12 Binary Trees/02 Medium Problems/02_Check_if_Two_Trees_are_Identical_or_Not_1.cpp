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
  void preorderTraversal(TreeNode *root, vector<int> &arr) {
    if (root == nullptr) {
      arr.push_back(INT_MIN);
      return;
    }

    arr.push_back(root->data);
    preorderTraversal(root->left, arr);
    preorderTraversal(root->right, arr);
  }

public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    vector<int> p_, q_;
    preorderTraversal(p, p_);
    preorderTraversal(q, q_);

    return p_ == q_;
  }
};

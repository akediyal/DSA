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
  bool helperFunc(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }

    if (p == nullptr || q == nullptr) {
      return false;
    }

    if (p->data != q->data) {
      return false;
    }

    return helperFunc(p->left, q->left) && helperFunc(p->right, q->right);
  }

public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    bool ans = helperFunc(p, q);
    return ans;
  }
};

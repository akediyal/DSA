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
  void inorderTraversal(TreeNode *root, TreeNode *&prev, TreeNode *&first,
                        TreeNode *&mid, TreeNode *&last) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, prev, first, mid, last);

    if (prev != nullptr && root->data < prev->data) {
      if (first == nullptr) {
        first = prev;
        mid = root;
      } else {
        last = root;
      }
    }

    prev = root;

    inorderTraversal(root->right, prev, first, mid, last);
  }

public:
  void recoverTree(TreeNode *root) {
    TreeNode *prev, *first, *mid, *last;
    prev = first = mid = last = nullptr;

    inorderTraversal(root, prev, first, mid, last);

    if (first != nullptr && last != nullptr) {
      swap(first->data, last->data);
    } else if (first != nullptr && mid != nullptr) {
      swap(first->data, mid->data);
    }
  }
};

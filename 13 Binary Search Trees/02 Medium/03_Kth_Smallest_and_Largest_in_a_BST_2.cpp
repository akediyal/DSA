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
  void reverseInorderTraversal(TreeNode *root, int &k, int &kth_largest) {
    if (root == nullptr) {
      return;
    }

    reverseInorderTraversal(root->right, k, kth_largest);

    if (--k == 0) {
      kth_largest = root->data;
      return;
    }

    reverseInorderTraversal(root->left, k, kth_largest);
  }

  void inorderTraversal(TreeNode *root, int &k, int &kth_smallest) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, k, kth_smallest);

    if (--k == 0) {
      kth_smallest = root->data;
      return;
    }

    inorderTraversal(root->right, k, kth_smallest);
  }

public:
  vector<int> kLargesSmall(TreeNode *root, int k) {
    int kth_smallest = -1;
    int kth_largest = -1;
    int k1 = k, k2 = k;

    inorderTraversal(root, k1, kth_smallest);
    reverseInorderTraversal(root, k2, kth_largest);

    return {kth_smallest, kth_largest};
  }
};

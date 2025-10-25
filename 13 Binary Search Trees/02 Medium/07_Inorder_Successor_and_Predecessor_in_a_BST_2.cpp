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
  void inorderTraversal(TreeNode *root, int key, int &predecessor,
                        int &successor) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, key, predecessor, successor);

    if (root->data < key) {
      predecessor = root->data;
    }

    if (root->data > key && successor == -1) {
      successor = root->data;
    }

    inorderTraversal(root->right, key, predecessor, successor);
  }

public:
  vector<int> succPredBST(TreeNode *root, int key) {
    int predecessor = -1, successor = -1;
    inorderTraversal(root, key, predecessor, successor);

    return {predecessor, successor};
  }
};

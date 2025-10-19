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
  void helperFunc(TreeNode *root, vector<int> &arr) {
    if (root == nullptr) {
      return;
    }

    arr.push_back(root->data);
    helperFunc(root->left, arr);
    helperFunc(root->right, arr);
  }

public:
  vector<int> preorder(TreeNode *root) {
    vector<int> ans;
    helperFunc(root, ans);
    return ans;
  }
};

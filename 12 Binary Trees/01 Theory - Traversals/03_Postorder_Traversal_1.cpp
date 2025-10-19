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
  void helperFunc(TreeNode *node, vector<int> &arr) {
    if (node == nullptr) {
      return;
    }

    helperFunc(node->left, arr);
    helperFunc(node->right, arr);
    arr.push_back(node->data);
  }

public:
  vector<int> postorder(TreeNode *root) {
    vector<int> ans;
    helperFunc(root, ans);
    return ans;
  }
};

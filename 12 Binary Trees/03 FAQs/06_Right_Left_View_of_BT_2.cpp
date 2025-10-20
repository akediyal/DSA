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
  void helperFunc(TreeNode *root, int level, vector<int> &ans) {
    if (root == nullptr) {
      return;
    }

    if (ans.size() == level) {
      ans.push_back(root->data);
    }

    helperFunc(root->right, level + 1, ans);
    helperFunc(root->left, level + 1, ans);
  }

public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    helperFunc(root, 0, ans);
    return ans;
  }
};

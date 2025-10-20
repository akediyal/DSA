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
  void helperFunc(TreeNode *root, vector<int> &arr, vector<vector<int>> &ans) {
    if (root == nullptr) {
      return;
    }

    arr.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr) {
      ans.push_back(arr);
    } else {
      helperFunc(root->left, arr, ans);
      helperFunc(root->right, arr, ans);
    }

    arr.pop_back();
  }

public:
  vector<vector<int>> allRootToLeaf(TreeNode *root) {
    vector<vector<int>> ans;
    vector<int> arr;

    if (root == nullptr) {
      return ans;
    }

    helperFunc(root, arr, ans);

    return ans;
  }
};

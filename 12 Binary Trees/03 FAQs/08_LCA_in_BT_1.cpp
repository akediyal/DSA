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
  bool helperFunc(TreeNode *root, TreeNode *p, vector<TreeNode *> &arr) {
    if (root == nullptr) {
      return false;
    }

    arr.push_back(root);

    if (root == p) {
      return true;
    }

    if (helperFunc(root->left, p, arr) || helperFunc(root->right, p, arr)) {
      return true;
    }

    arr.pop_back();

    return false;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> arr1, arr2;

    helperFunc(root, p, arr1);
    helperFunc(root, q, arr2);

    TreeNode *ans = nullptr;
    int n = min(arr1.size(), arr2.size());

    for (int i = 0; i < n; i++) {
      if (arr1[i] == arr2[i]) {
        ans = arr1[i];
      } else {
        break;
      }
    }

    return ans;
  }
};

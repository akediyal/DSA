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
  bool helperFunc(TreeNode *root, int p, vector<TreeNode *> &arr) {
    if (root == nullptr) {
      return false;
    }

    arr.push_back(root);

    if (root->data == p) {
      return true;
    }

    bool left = helperFunc(root->left, p, arr);
    bool right = helperFunc(root->right, p, arr);

    if (left || right) {
      return true;
    }

    arr.pop_back();

    return false;
  }

public:
  TreeNode *lca(TreeNode *root, int p, int q) {
    vector<TreeNode *> arr1, arr2;

    helperFunc(root, p, arr1);
    helperFunc(root, q, arr2);

    if (arr1.size() == 0 || arr2.size() == 0) {
      return nullptr;
    }

    int idx = 0;

    while (idx < arr1.size() && idx < arr2.size() && arr1[idx] == arr2[idx]) {
      idx++;
    }

    return arr1[idx - 1];
  }
};

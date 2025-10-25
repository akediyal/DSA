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
  TreeNode *helperFunc(vector<int> &preorder, int bound, int &idx) {
    if (idx == preorder.size() || preorder[idx] > bound) {
      return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[idx++]);

    root->left = helperFunc(preorder, root->data, idx);
    root->right = helperFunc(preorder, bound, idx);

    return root;
  }

public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    int idx = 0;
    return helperFunc(preorder, INT_MAX, idx);
  }
};

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
  int findMaxPathSum(TreeNode *root, int &mx) {
    if (root == nullptr) {
      return 0;
    }

    int left_max_path = max(0, findMaxPathSum(root->left, mx));
    int right_max_path = max(0, findMaxPathSum(root->right, mx));

    mx = max(mx, left_max_path + right_max_path + root->data);

    return root->data + max(left_max_path, right_max_path);
  }

public:
  int maxPathSum(TreeNode *root) {
    int mx = INT_MIN;
    findMaxPathSum(root, mx);
    return mx;
  }
};

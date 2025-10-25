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
  void inorderTraversal(TreeNode *root, vector<int> &inorder) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
  }

  bool twoSum(TreeNode *root, int k, vector<int> &inorder) {
    int left = 0, right = inorder.size() - 1;
    int sum = 0;

    while (left < right) {
      sum = inorder[left] + inorder[right];

      if (sum > k) {
        right--;
      } else if (sum < k) {
        left++;
      } else {
        return true;
      }
    }

    return false;
  }

public:
  bool twoSumBST(TreeNode *root, int k) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    return twoSum(root, k, inorder);
  }
};

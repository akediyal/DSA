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
  void inorderTraversal(TreeNode *root, vector<int> &inorder) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
  }

  int binarySearch(vector<int> &arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] > key) {
        high = mid - 1;
      } else if (arr[mid] < key) {
        low = mid + 1;
      } else {
        return mid;
      }
    }

    return -1;
  }

public:
  vector<int> succPredBST(TreeNode *root, int key) {
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int idx = binarySearch(inorder, key);

    int predecessor = (idx > 0) ? inorder[idx - 1] : -1;
    int sucessor = (idx < inorder.size() - 1) ? inorder[idx + 1] : -1;

    return {predecessor, sucessor};
  }
};

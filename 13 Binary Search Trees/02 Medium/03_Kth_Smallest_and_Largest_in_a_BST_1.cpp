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
  void preorderTraversal(TreeNode *root, vector<int> &nodes) {
    if (root == nullptr) {
      return;
    }

    nodes.push_back(root->data);
    preorderTraversal(root->left, nodes);
    preorderTraversal(root->right, nodes);
  }

public:
  vector<int> kLargesSmall(TreeNode *root, int k) {
    vector<int> ans;
    preorderTraversal(root, ans);

    sort(ans.begin(), ans.end());

    int kth_smallest = ans[k - 1];
    int kth_largest = ans[ans.size() - k];

    return {kth_smallest, kth_largest};
  }
};

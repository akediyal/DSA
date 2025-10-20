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
  vector<vector<int>> levelOrderTraversal(TreeNode *root) {
    vector<vector<int>> ans;

    if (root == nullptr) {
      return ans;
    }

    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty()) {
      int n = q.size();
      vector<int> arr(n);

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();

        int index = flag ? i : (n - i - 1);
        arr[index] = node->data;

        if (node->left != nullptr) {
          q.push(node->left);
        }

        if (node->right != nullptr) {
          q.push(node->right);
        }
      }

      flag = !flag;
      ans.push_back(arr);
    }

    return ans;
  }

public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans = levelOrderTraversal(root);
    return ans;
  }
};

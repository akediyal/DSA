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
  int levelOrderTraversal(TreeNode *node) {
    queue<TreeNode *> q;
    q.push(node);
    int depth = 0;

    while (!q.empty()) {
      depth++;
      int n = q.size();

      for (int i = 0; i < n; i++) {
        TreeNode *temp = q.front();
        q.pop();

        if (temp->left != nullptr) {
          q.push(temp->left);
        }

        if (temp->right != nullptr) {
          q.push(temp->right);
        }
      }
    }

    return depth;
  }

public:
  int maxDepth(TreeNode *root) {
    int ans = levelOrderTraversal(root);
    return ans;
  }
};

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
  map<int, int> levelOrderTraversal(TreeNode *root) {
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      TreeNode *node = p.first;
      int line = p.second;

      if (mp.find(line) == mp.end()) {
        mp[line] = node->data;
      }

      if (node->left != nullptr) {
        q.push({node->left, line - 1});
      }

      if (node->right != nullptr) {
        q.push({node->right, line + 1});
      }
    }

    return mp;
  }

public:
  vector<int> topView(TreeNode *root) {
    vector<int> ans;

    if (root == nullptr) {
      return ans;
    }

    map<int, int> mp = levelOrderTraversal(root);

    for (auto &[line, data] : mp) {
      ans.push_back(data);
    }

    return ans;
  }
};

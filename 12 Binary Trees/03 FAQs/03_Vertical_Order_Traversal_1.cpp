/** Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
private:
  map<int, map<int, multiset<int>>> levelOrderTraversal(TreeNode *root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      TreeNode *node = p.first;
      int x = p.second.first;
      int y = p.second.second;
      nodes[x][y].insert(node->data);

      if (node->left != nullptr) {
        q.push({node->left, {x - 1, y + 1}});
      }

      if (node->right != nullptr) {
        q.push({node->right, {x + 1, y + 1}});
      }
    }

    return nodes;
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    auto nodes = levelOrderTraversal(root);
    vector<vector<int>> ans;

    for (auto p : nodes) {
      vector<int> col;

      for (auto q : p.second) {
        col.insert(col.end(), q.second.begin(), q.second.end());
      }

      ans.push_back(col);
    }

    return ans;
  }
};

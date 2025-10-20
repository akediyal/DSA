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
  void preorderTraversal(TreeNode *node, int x, int y,
                         map<int, map<int, multiset<int>>> &nodes) {
    if (node == nullptr) {
      return;
    }

    nodes[x][y].insert(node->data);
    preorderTraversal(node->left, x - 1, y + 1, nodes);
    preorderTraversal(node->right, x + 1, y + 1, nodes);
  }

public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, map<int, multiset<int>>> nodes;

    preorderTraversal(root, 0, 0, nodes);
    vector<vector<int>> ans;

    for (auto &[x, col_map] : nodes) {
      vector<int> col;

      for (auto &[y, ms] : col_map) {
        col.insert(col.end(), ms.begin(), ms.end());
      }

      ans.push_back(col);
    }

    return ans;
  }
};

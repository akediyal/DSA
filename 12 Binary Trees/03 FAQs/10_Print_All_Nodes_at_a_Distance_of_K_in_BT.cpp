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
  void markParents(TreeNode *root, TreeNode *target,
                   unordered_map<TreeNode *, TreeNode *> &parents) {
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      if (node->left != nullptr) {
        parents[node->left] = node;
        q.push(node->left);
      }

      if (node->right != nullptr) {
        parents[node->right] = node;
        q.push(node->right);
      }
    }
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<TreeNode *, TreeNode *> parents;
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;

    markParents(root, target, parents);

    q.push(target);
    visited[target] = true;
    int level = 0;

    while (!q.empty()) {
      int n = q.size();

      if (level == k) {
        break;
      }

      level++;

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (node->left != nullptr && visited[node->left] != true) {
          q.push(node->left);
          visited[node->left] = true;
        }

        if (node->right != nullptr && visited[node->right] != true) {
          q.push(node->right);
          visited[node->right] = true;
        }

        if (parents[node] != nullptr && visited[parents[node]] != true) {
          q.push(parents[node]);
          visited[parents[node]] = true;
        }
      }
    }

    vector<int> ans;

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      ans.push_back(node->data);
    }

    return ans;
  }
};

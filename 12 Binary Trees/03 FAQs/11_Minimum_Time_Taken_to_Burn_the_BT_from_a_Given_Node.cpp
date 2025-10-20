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
  TreeNode *bfsToMarkParents(TreeNode *root, int start,
                             unordered_map<TreeNode *, TreeNode *> &parents) {
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *start_node = new TreeNode(-1);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      if (node->data == start) {
        start_node = node;
      }

      if (node->left != nullptr) {
        parents[node->left] = node;
        q.push(node->left);
      }

      if (node->right != nullptr) {
        parents[node->right] = node;
        q.push(node->right);
      }
    }

    return start_node;
  }

  int findMaxDistance(TreeNode *target,
                      unordered_map<TreeNode *, TreeNode *> &parents) {
    queue<TreeNode *> q;
    unordered_map<TreeNode *, bool> visited;

    int time = 0;
    q.push(target);
    visited[target] = 1;

    while (!q.empty()) {
      int n = q.size();
      bool flag = false;

      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (node->left != nullptr && visited[node->left] == false) {
          flag = true;
          visited[node->left] = true;
          q.push(node->left);
        }

        if (node->right != nullptr && visited[node->right] == false) {
          flag = true;
          visited[node->right] = true;
          q.push(node->right);
        }

        if (parents.find(node) != parents.end() &&
            visited[parents[node]] == false) {
          flag = true;
          visited[parents[node]] = true;
          q.push(parents[node]);
        }
      }

      if (flag) {
        time++;
      }
    }

    return time;
  }

public:
  int timeToBurnTree(TreeNode *root, int start) {
    unordered_map<TreeNode *, TreeNode *> parents;

    TreeNode *target = bfsToMarkParents(root, start, parents);
    int time = findMaxDistance(target, parents);

    return time;
  }
};

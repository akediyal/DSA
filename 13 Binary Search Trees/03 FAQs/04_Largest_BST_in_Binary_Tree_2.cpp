/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class NodeValue {
public:
  int max_node, min_node, max_size;

  NodeValue(int min_node, int max_node, int max_size) {
    this->min_node = min_node;
    this->max_node = max_node;
    this->max_size = max_size;
  }
};

class Solution {
private:
  NodeValue helperFunc(TreeNode *root) {
    if (root == nullptr) {
      return NodeValue(INT_MAX, INT_MIN, 0);
    }

    auto left = helperFunc(root->left);
    auto right = helperFunc(root->right);

    if (left.max_node < root->data && right.min_node > root->data) {
      int size = left.max_size + right.max_size + 1;
      return NodeValue(min(root->data, left.min_node),
                       max(root->data, right.max_node), size);
    }

    return NodeValue(INT_MIN, INT_MAX, max(left.max_size, right.max_size));
  }

public:
  int largestBST(TreeNode *root) { return helperFunc(root).max_size; }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
class BSTIterator {
private:
  stack<TreeNode *> st;
  bool reverse;

  void pushNodes(TreeNode *root) {
    while (root != nullptr) {
      st.push(root);
      root = (reverse) ? root->right : root->left;
    }
  }

public:
  BSTIterator(TreeNode *root, bool isReverse) {
    reverse = isReverse;
    pushNodes(root);
  }

  bool hasNext() { return !st.empty(); }

  int next() {
    TreeNode *node = st.top();
    st.pop();

    if (reverse) {
      pushNodes(node->left);
    } else {
      pushNodes(node->right);
    }

    return node->data;
  }
};

class Solution {
private:
  bool twoSum(TreeNode *root, int k) {
    if (root == nullptr) {
      return false;
    }

    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int left = l.next();
    int right = r.next();

    while (left < right) {
      int sum = left + right;

      if (sum > k) {
        right = r.next();
      } else if (sum < k) {
        left = l.next();
      } else {
        return true;
      }
    }

    return false;
  }

public:
  bool twoSumBST(TreeNode *root, int k) { return twoSum(root, k); }
};

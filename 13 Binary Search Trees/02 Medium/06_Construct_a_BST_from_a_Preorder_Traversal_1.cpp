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
public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    if (preorder.size() == 0) {
      return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> st;
    st.push(root);

    for (int i = 1; i < preorder.size(); i++) {
      TreeNode *node = st.top();
      TreeNode *child = new TreeNode(preorder[i]);

      while (!st.empty() && st.top()->data < preorder[i]) {
        node = st.top();
        st.pop();
      }

      if (node->data < preorder[i]) {
        node->right = child;
      } else {
        node->left = child;
      }

      st.push(child);
    }

    return root;
  }
};

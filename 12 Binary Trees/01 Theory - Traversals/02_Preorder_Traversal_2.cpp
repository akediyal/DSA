/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
  vector<int> preorder(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      ans.push_back(node->data);

      if (node->right != nullptr) {
        st.push(node->right);
      }

      if (node->left != nullptr) {
        st.push(node->left);
      }
    }

    return ans;
  }
};

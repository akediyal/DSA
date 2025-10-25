/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator {
private:
  vector<int> inorder;
  int idx;

  void inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left);
    inorder.push_back(root->data);
    inorderTraversal(root->right);
  }

public:
  BSTIterator(TreeNode *root) {
    inorderTraversal(root);
    idx = -1;
  }

  bool hasNext() { return idx + 1 < inorder.size(); }

  int next() { return inorder[++idx]; }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

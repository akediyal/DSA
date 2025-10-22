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
  TreeNode *helperFunc(vector<int> &inorder, int in_start, int in_end,
                       vector<int> &postorder, int post_start, int post_end,
                       unordered_map<int, int> &mp) {
    if (in_start > in_end || post_start > post_end) {
      return nullptr;
    }

    TreeNode *root = new TreeNode(postorder[post_end]);
    int in_root = mp[root->data];
    int nums_left = in_root - in_start;

    root->left = helperFunc(inorder, in_start, in_root - 1, postorder,
                            post_start, post_start + nums_left - 1, mp);
    root->right = helperFunc(inorder, in_root + 1, in_end, postorder,
                             post_start + nums_left, post_end - 1, mp);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int in_size = inorder.size();
    int post_size = postorder.size();

    if (in_size == 0 || post_size == 0 || in_size != post_size) {
      return nullptr;
    }

    unordered_map<int, int> mp;

    for (int i = 0; i < in_size; i++) {
      mp[inorder[i]] = i;
    }

    return helperFunc(inorder, 0, in_size - 1, postorder, 0, post_size - 1, mp);
  }
};

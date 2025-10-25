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
  TreeNode *buildTree(vector<int> &preorder, int pre_start, int pre_end,
                      int in_start, int in_end, unordered_map<int, int> &mp) {
    if (pre_start > pre_end || in_start > in_end) {
      return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[pre_start]);
    int in_root = mp[root->data];
    int nums_left = in_root - in_start;

    root->left = buildTree(preorder, pre_start + 1, pre_start + nums_left,
                           in_start, in_root - 1, mp);

    root->right = buildTree(preorder, pre_start + nums_left + 1, pre_end,
                            in_root + 1, in_end, mp);

    return root;
  }

public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());

    unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++) {
      mp[inorder[i]] = i;
    }

    return buildTree(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1,
                     mp);
  }
};

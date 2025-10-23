/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
private:
  int floorOfBST(TreeNode *root, int key) {
    int floor = -1;

    while (root != nullptr) {
      if (root->data == key) {
        floor = root->data;
        break;
      } else if (root->data < key) {
        floor = root->data;
        root = root->right;
      } else {
        root = root->left;
      }
    }

    return floor;
  }

  int ceilOfBST(TreeNode *root, int key) {
    int ceil = -1;

    while (root != nullptr) {
      if (root->data == key) {
        ceil = root->data;
        break;
      } else if (root->data > key) {
        ceil = root->data;
        root = root->left;
      } else {
        root = root->right;
      }
    }

    return ceil;
  }

public:
  vector<int> floorCeilOfBST(TreeNode *root, int key) {
    int floor = floorOfBST(root, key);
    int ceil = ceilOfBST(root, key);

    return {floor, ceil};
  }
};

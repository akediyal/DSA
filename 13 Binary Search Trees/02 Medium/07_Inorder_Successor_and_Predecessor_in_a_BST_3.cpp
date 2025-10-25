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
  void helperFunc(TreeNode *root, int key, int &predecessor, int &successor) {
    while (root != nullptr) {
      if (root->data < key) {
        predecessor = root->data;
        root = root->right;
      } else if (root->data > key) {
        successor = root->data;
        root = root->left;
      } else {
        if (root->left != nullptr) {
          TreeNode *temp = root->left;

          while (temp->right != nullptr) {
            temp = temp->right;
          }

          predecessor = temp->data;
        }

        if (root->right != nullptr) {
          TreeNode *temp = root->right;

          while (temp->left != nullptr) {
            temp = temp->left;
          }

          successor = temp->data;
        }

        break;
      }
    }
  }

public:
  vector<int> succPredBST(TreeNode *root, int key) {
    int predecessor = -1, successor = -1;
    helperFunc(root, key, predecessor, successor);

    return {predecessor, successor};
  }
};

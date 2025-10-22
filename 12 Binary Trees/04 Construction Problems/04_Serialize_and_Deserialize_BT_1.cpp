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
  string serialize(TreeNode *root) {
    if (root == nullptr) {
      return "";
    }

    string s = "";
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      if (node == nullptr) {
        s.append("#,");
      } else {
        s.append(to_string(node->data) + ',');
      }

      if (node != nullptr) {
        q.push(node->left);
        q.push(node->right);
      }
    }

    return s;
  }

  TreeNode *deserialize(string data) {
    if (data.size() == 0) {
      return nullptr;
    }

    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      getline(s, str, ',');

      if (str == "#") {
        node->left = nullptr;
      } else {
        TreeNode *left = new TreeNode(stoi(str));
        node->left = left;
        q.push(left);
      }

      getline(s, str, ',');

      if (str == "#") {
        node->right = nullptr;
      } else {
        TreeNode *right = new TreeNode(stoi(str));
        node->right = right;
        q.push(right);
      }
    }

    return root;
  }
};

/*
 * Your Codec object will be instantiated and called as such:
 * Codec* ser = new Codec();
 * Codec* deser = new Codec();
 * string tree = ser->serialize(root);
 * TreeNode* ans = deser->deserialize(tree);
 * return ans;
 */

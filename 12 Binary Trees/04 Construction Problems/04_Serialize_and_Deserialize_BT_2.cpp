class Solution {
public:
  string serialize(TreeNode *root) {
    if (root == nullptr) {
      return "";
    }

    stringstream ss;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      if (node == nullptr) {
        ss << "#,";
      } else {
        ss << node->data << ",";
        q.push(node->left);
        q.push(node->right);
      }
    }

    return ss.str();
  }

  TreeNode *deserialize(string data) {
    if (data.empty()) {
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

      if (str != "#") {
        TreeNode *left = new TreeNode(stoi(str));
        node->left = left;
        q.push(left);
      }

      getline(s, str, ',');

      if (str != "#") {
        TreeNode *right = new TreeNode(stoi(str));
        node->right = right;
        q.push(right);
      }
    }

    return root;
  }
};

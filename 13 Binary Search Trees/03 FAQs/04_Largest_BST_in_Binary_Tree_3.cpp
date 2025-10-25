class Solution {
public:
  tuple<int, bool, int, int> isBSTAndSize(TreeNode *node, int minValue,
                                          int maxValue) {
    if (!node) {
      return make_tuple(0, true, INT_MAX, INT_MIN);
    }

    auto [leftSize, isLeftBST, leftMin, leftMax] =
        isBSTAndSize(node->left, minValue, node->data);

    auto [rightSize, isRightBST, rightMin, rightMax] =
        isBSTAndSize(node->right, node->data, maxValue);

    if (isLeftBST && isRightBST &&
        (leftMax < node->data && node->data < rightMin)) {
      int size = leftSize + rightSize + 1;
      return make_tuple(size, true, min(node->data, leftMin),
                        max(node->data, rightMax));
    } else {
      return make_tuple(max(leftSize, rightSize), false, INT_MIN, INT_MAX);
    }
  }

  int largestBST(TreeNode *root) {
    return get<0>(isBSTAndSize(root, INT_MIN, INT_MAX));
  }
};

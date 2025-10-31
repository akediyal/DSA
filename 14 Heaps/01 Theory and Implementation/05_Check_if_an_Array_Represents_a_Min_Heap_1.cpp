class Solution {
private:
  bool helperFunc(vector<int> &nums, int ind) {
    int n = nums.size();
    int left_child_node = 2 * ind + 1;
    int right_child_node = 2 * ind + 2;

    if (left_child_node >= n && right_child_node >= n) {
      return true;
    }

    if (left_child_node < n && nums[left_child_node] < nums[ind]) {
      return false;
    }

    if (right_child_node < n && nums[right_child_node] < nums[ind]) {
      return false;
    }

    bool left = true, right = true;

    if (left_child_node < n) {
      left = helperFunc(nums, left_child_node);
    }

    if (right_child_node < n) {
      right = helperFunc(nums, right_child_node);
    }

    return left && right;
  }

public:
  bool isHeap(vector<int> &nums) { return helperFunc(nums, 0); }
};

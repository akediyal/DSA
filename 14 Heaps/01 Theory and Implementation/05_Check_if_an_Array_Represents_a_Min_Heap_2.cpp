class Solution {
public:
  bool isHeap(vector<int> &nums) {
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
      int left_child_ind = 2 * i + 1;
      int right_child_ind = 2 * i + 2;

      if (left_child_ind < n && nums[left_child_ind] < nums[i]) {
        return false;
      }

      if (right_child_ind < n && nums[right_child_ind] < nums[i]) {
        return false;
      }
    }

    return true;
  }
};

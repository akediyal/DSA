class Solution {
public:
  vector<int> reverseArray(vector<int> &nums) {
    // your code goes here
    reverse(nums, 0, nums.size() - 1);
    return nums;
  }
  void reverse(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return;
    }
    swap(nums[left], nums[right]);
    reverse(nums, left + 1, right - 1);
  }
};

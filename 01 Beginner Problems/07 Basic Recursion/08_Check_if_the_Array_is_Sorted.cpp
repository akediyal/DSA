class Solution {
public:
  bool isSorted(vector<int> &nums) {
    // your code goes here
    if (nums.size() <= 1) {
      return true;
    }
    return checkSort(nums, 0, 1);
  }
  bool checkSort(vector<int> &nums, int cur, int curNext) {
    if (cur >= nums.size() - 2) {
      return true;
    }
    if (nums[cur] > nums[curNext]) {
      return false;
    }
    return checkSort(nums, cur + 1, curNext + 1);
  }
};

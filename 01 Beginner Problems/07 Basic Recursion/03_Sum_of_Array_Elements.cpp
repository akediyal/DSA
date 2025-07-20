class Solution {
public:
  int arraySum(vector<int> &nums) {
    // your code goes here
    return sumOfArrayElements(nums, nums.size() - 1);
  }

  int sumOfArrayElements(vector<int> &nums, int cur) {
    if (cur < 0) {
      return 0;
    }
    return nums[cur] + sumOfArrayElements(nums, cur - 1);
  }
};

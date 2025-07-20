class Solution {
public:
  vector<int> reverseArray(vector<int> &nums) {
    // your code goes here
    vector<int> reversed_arr;
    reverse(nums, nums.size() - 1, reversed_arr);
    return reversed_arr;
  }
  void reverse(vector<int> &nums, int cur, vector<int> &reversed_arr) {
    if (cur < 0) {
      return;
    }
    reversed_arr.push_back(nums[cur]);
    reverse(nums, cur - 1, reversed_arr);
  }
};

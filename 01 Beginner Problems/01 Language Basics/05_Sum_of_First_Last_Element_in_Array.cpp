class Solution {
public:
  int sumOfFirstAndLast(vector<int> &nums) {
    int first = nums[0];
    int last = nums[nums.size() - 1];
    return first + last;
  }
};

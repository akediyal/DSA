class Solution {
private:
  bool helperFunc(vector<int> &nums, int idx, int sum) {
    if (idx == nums.size()) {
      return sum == 0;
    }

    return helperFunc(nums, idx + 1, sum - nums[idx]) |
           helperFunc(nums, idx + 1, sum);
  }

public:
  bool checkSubsequenceSum(vector<int> &nums, int k) {
    bool ans = helperFunc(nums, 0, k);
    return ans;
  }
};

class Solution {
private:
  bool helperFunc(vector<int> &nums, int idx, int sum) {
    if (sum == 0) {
      return true;
    }

    if (idx == nums.size() || sum < 0) {
      return false;
    }

    bool path1 = helperFunc(nums, idx + 1, sum - nums[idx]);
    bool path2 = helperFunc(nums, idx + 1, sum);

    return path1 || path2;
  }

public:
  bool checkSubsequenceSum(vector<int> &nums, int k) {
    bool ans = helperFunc(nums, 0, k);
    return ans;
  }
};

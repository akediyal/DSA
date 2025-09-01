class Solution {
private:
  int helperFunc(vector<int> &nums, int idx, int sum) {
    if (sum == 0) {
      return 1;
    }

    if (idx == nums.size() || sum < 0) {
      return 0;
    }

    int path1 = helperFunc(nums, idx + 1, sum - nums[idx]);
    int path2 = helperFunc(nums, idx + 1, sum);

    return path1 + path2;
  }

public:
  int countSubsequenceWithTargetSum(vector<int> &nums, int k) {
    int ans = helperFunc(nums, 0, k);
    return ans;
  }
};

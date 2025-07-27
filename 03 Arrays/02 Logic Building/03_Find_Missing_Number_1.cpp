class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    if (nums[n - 1] != n) {
      return n;
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
      if (nums[i] - nums[i - 1] != 1) {
        ans = nums[i] - 1;
        return ans;
      }
    }

    return ans;
  }
};

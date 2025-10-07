class Solution {
private:
  int helperFunc(vector<int> &nums, int k) {
    int n = nums.size();

    if (k < 0) {
      return 0;
    }

    int l = 0, r = 0;
    int sum = 0;
    int cnt = 0;

    while (r < n) {
      sum += nums[r] % 2;

      if (sum > k) {
        while (sum > k) {
          sum -= nums[l] % 2;
          l++;
        }
      }

      if (sum <= k) {
        int len = r - l + 1;
        cnt += len;
      }

      r++;
    }

    return cnt;
  }

public:
  int numberOfOddSubarrays(vector<int> &nums, int k) {
    return helperFunc(nums, k) - helperFunc(nums, k - 1);
  }
};

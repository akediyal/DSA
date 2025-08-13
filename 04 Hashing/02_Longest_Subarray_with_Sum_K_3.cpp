class Solution {
public:
  int longestSubarray(vector<int> &nums, int k) {
    int n = nums.size();

    map<int, int> prefix_sum;
    int sum = 0, longest = 0;

    for (int i = 0; i < n; i++) {
      sum += nums[i];

      if (sum == k) {
        longest = i + 1;
      }

      int rem = sum - k;

      if (prefix_sum.find(rem) != prefix_sum.end()) {
        int len = i - prefix_sum[rem];
        longest = max(longest, len);
      }

      if (prefix_sum.find(sum) == prefix_sum.end()) {
        prefix_sum[sum] = i;
      }
    }

    return longest;
  }
};

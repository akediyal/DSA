class Solution {
public:
  int longestSubarray(vector<int> &nums, int k) {
    int n = nums.size();

    int longest = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int sum = 0;

        for (int k = i; k <= j; k++) {
          sum += nums[k];
        }

        if (sum == k) {
          longest = max(longest, j - i + 1);
        }
      }
    }

    return longest;
  }
};

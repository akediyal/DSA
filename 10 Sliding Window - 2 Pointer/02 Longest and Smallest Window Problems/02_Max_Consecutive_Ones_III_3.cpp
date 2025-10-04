class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int max_len = 0;
    int zeroes = 0;
    int l = 0, r = 0;

    while (r < n) {
      if (nums[r] == 0) {
        zeroes++;
      }

      if (zeroes > k) {
        if (nums[l] == 0) {
          zeroes--;
        }
        l++;
      }

      if (zeroes <= k) {
        int len = r - l + 1;
        max_len = max(max_len, len);
      }

      r++;
    }

    return max_len;
  }
};

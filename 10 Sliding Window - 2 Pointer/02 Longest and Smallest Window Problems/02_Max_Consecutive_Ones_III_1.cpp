class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();
    int max_len = 0;

    for (int i = 0; i < n; i++) {
      int zeroes = 0;

      for (int j = i; j < n; j++) {
        if (nums[j] == 0) {
          zeroes++;
        }

        if (zeroes <= k) {
          int len = j - i + 1;
          max_len = max(max_len, len);
        } else {
          break;
        }
      }
    }

    return max_len;
  }
};

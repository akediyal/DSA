class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int n = nums.size();

    if (n == 2) {
      if (nums[0] < nums[1]) {
        return {nums[0], nums[1]};
      } else {
        return {nums[1], nums[0]};
      }
    }

    long xorr = 0;

    for (int i = 0; i < n; i++) {
      xorr ^= nums[i];
    }

    int rightmost = (xorr & (xorr - 1)) ^ xorr;
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] & rightmost) {
        xor1 ^= nums[i];
      } else {
        xor2 ^= nums[i];
      }
    }

    if (xor1 < xor2) {
      return {xor1, xor2};
    } else {
      return {xor2, xor1};
    }
  }
};

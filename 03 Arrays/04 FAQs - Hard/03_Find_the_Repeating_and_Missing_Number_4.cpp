class Solution {
public:
  vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    int n = nums.size();

    int xr = 0;

    for (int i = 0; i < n; i++) {
      xr = xr ^ nums[i];
      xr = xr ^ (i + 1);
    }

    int bit_num = 0;

    while (1) {
      if ((xr & (1 << bit_num)) != 0) {
        break;
      }
      bit_num++;
    }

    int zero = 0, one = 0;

    for (int i = 0; i < n; i++) {
      if ((nums[i] & (1 << bit_num)) != 0) {
        one = one ^ nums[i];
      } else {
        zero = zero ^ nums[i];
      }
    }

    for (int i = 1; i <= n; i++) {
      if ((i & (1 << bit_num)) != 0) {
        one = one ^ i;
      } else {
        zero = zero ^ i;
      }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] == zero) {
        cnt++;
      }
    }

    if (cnt == 2) {
      return {zero, one};
    } else {
      return {one, zero};
    }
  }
};

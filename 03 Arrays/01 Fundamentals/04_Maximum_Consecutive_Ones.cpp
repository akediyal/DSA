class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size();

    int count_ones = 0;
    int max_count = 0;

    for (auto i : nums) {
      if (i == 1) {
        count_ones++;

        if (count_ones > max_count) {
          max_count = count_ones;
        }

      } else {
        count_ones = 0;
      }
    }

    return max_count;
  }
};

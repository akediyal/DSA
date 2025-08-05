class Solution {
public:
  vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    long long n = nums.size();

    long long sum_n = 0, sum_n_square = 0;

    sum_n = (n * (n + 1)) / 2;
    sum_n_square = (n * (n + 1) * (2 * n + 1)) / 6;

    long long sum = 0, sum_square = 0;

    for (int i = 0; i < n; i++) {
      sum += nums[i];
      sum_square += (long long)nums[i] * (long long)nums[i];
    }

    long long temp1 = sum - sum_n;
    long long temp2 = sum_square - sum_n_square;

    temp2 = temp2 / temp1;

    long long repeating = (temp1 + temp2) / 2;
    long long missing = repeating - temp1;

    return {(int)repeating, (int)missing};
  }
};

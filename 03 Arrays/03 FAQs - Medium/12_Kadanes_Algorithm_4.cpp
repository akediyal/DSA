class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    long long sum = 0, max_sum = LLONG_MIN;

    int initial_index = 0;
    int start_index = -1, end_index = -1;

    for (int i = 0; i < n; i++) {

      if (sum == 0) {
        initial_index = i;
      }

      sum += nums[i];

      if (sum > max_sum) {
        max_sum = sum;
        start_index = initial_index;
        end_index = i;
      }

      if (sum < 0) {
        sum = 0;
      }
    }

    for (int i = start_index; i <= end_index; i++) {
      cout << nums[i] << " \n"[i == end_index];
    }

    return max_sum;
  }
};

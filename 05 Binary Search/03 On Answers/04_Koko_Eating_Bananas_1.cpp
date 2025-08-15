class Solution {
private:
  long long calculateTotalHours(vector<int> &nums, int n, int hourly) {
    long long total_hrs = 0;

    for (int i = 0; i < n; i++) {
      total_hrs += (nums[i] + hourly - 1) / hourly;
    }

    return total_hrs;
  }

public:
  int minimumRateToEatBananas(vector<int> nums, int h) {
    int n = nums.size();

    int max_el = *max_element(nums.begin(), nums.end());

    for (int i = 1; i <= max_el; i++) {
      long long req_time = calculateTotalHours(nums, n, i);

      if (req_time <= (long long)h) {
        return i;
      }
    }

    return max_el;
  }
};

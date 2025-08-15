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

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high) {
      int mid = low + (high - low) / 2;
      long long req_time = calculateTotalHours(nums, n, mid);

      if (req_time <= (long long)h) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};

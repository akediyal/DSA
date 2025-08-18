class Solution {
private:
  bool isPossible(vector<int> &nums, int day, int m, int k) {
    int n = nums.size();

    int cnt = 0;
    int bouquets = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] <= day) {
        cnt++;
      } else {
        bouquets += (cnt / k);
        cnt = 0;
      }
    }

    bouquets += (cnt / k);

    return bouquets >= m;
  }

public:
  int roseGarden(int n, vector<int> nums, int k, int m) {
    long long val = m * 1LL * k * 1LL;

    if (val > n) {
      return -1;
    }

    int min_el = INT_MAX, max_el = INT_MIN;

    for (int i = 0; i < n; i++) {
      min_el = min(min_el, nums[i]);
      max_el = max(max_el, nums[i]);
    }

    int low = min_el, high = max_el;
    int ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (isPossible(nums, mid, m, k)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }
};

class Solution {
private:
  bool canWePlace(vector<int> &nums, int dist, int cows) {
    int n = nums.size();

    int cnt_cows = 1, last = nums[0];

    for (int i = 0; i < n; i++) {
      if (nums[i] - last >= dist) {
        cnt_cows++;
        last = nums[i];
      }

      if (cnt_cows >= cows) {
        return true;
      }
    }

    return false;
  }

public:
  int aggressiveCows(vector<int> &nums, int k) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int low = 1;
    int high = nums[n - 1] - nums[0];

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (canWePlace(nums, mid, k)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return high;
  }
};

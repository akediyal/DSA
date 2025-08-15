class Solution {
private:
  int sumOfDivisions(vector<int> &nums, int n, int d) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += (nums[i] + d - 1) / d;
    }

    return sum;
  }

public:
  int smallestDivisor(vector<int> &nums, int limit) {
    int n = nums.size();

    if (n > limit) {
      return -1;
    }

    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int sum = sumOfDivisions(nums, n, mid);

      if (sum <= limit) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return low;
  }
};

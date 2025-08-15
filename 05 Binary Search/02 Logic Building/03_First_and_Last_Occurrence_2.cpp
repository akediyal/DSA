class Solution {
private:
  int lowerBound(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] >= target) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

  int upperBound(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] > target) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();

    int first_occ = lowerBound(nums, n, target);

    if (first_occ == n || nums[first_occ] != target) {
      return {-1, -1};
    }

    int second_occ = upperBound(nums, n, target) - 1;

    return {first_occ, second_occ};
  }
};

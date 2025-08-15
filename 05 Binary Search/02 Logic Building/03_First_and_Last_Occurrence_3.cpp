class Solution {
private:
  int getFirstOccurrence(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target) {
        ans = mid;
        high = mid - 1;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans;
  }

  int getLastOccurrence(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target) {
        ans = mid;
        low = mid + 1;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();

    int first_occ = getFirstOccurrence(nums, n, target);

    if (first_occ == n) {
      return {-1, -1};
    }

    int second_occ = getLastOccurrence(nums, n, target);

    return {first_occ, second_occ};
  }
};

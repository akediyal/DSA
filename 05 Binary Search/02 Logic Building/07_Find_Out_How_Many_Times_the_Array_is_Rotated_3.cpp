class Solution {
public:
  int findKRotation(vector<int> &nums) {
    int n = nums.size();

    int low = 0, high = n - 1;
    int min_el = INT_MAX;
    int ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[low] <= nums[high]) {
        if (nums[low] < min_el) {
          min_el = nums[low];
          ans = low;
        }

        break;
      }

      if (nums[low] <= nums[mid]) {
        if (nums[low] < min_el) {
          min_el = nums[low];
          ans = low;
        }

        low = mid + 1;
      }

      else {
        if (nums[mid] < min_el) {
          min_el = nums[mid];
          ans = mid;
        }

        high = mid - 1;
      }
    }

    return ans;
  }
};

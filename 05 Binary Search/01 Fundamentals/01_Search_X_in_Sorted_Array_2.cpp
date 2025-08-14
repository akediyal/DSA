class Solution {
private:
  int binarySearch(vector<int> &nums, int low, int high, int target) {
    if (low > high) {
      return -1;
    }

    int mid = low + (high - low) / 2;
    int index = 0;

    if (nums[mid] == target) {
      index = mid;
    } else if (nums[mid] > target) {
      index = binarySearch(nums, low, mid - 1, target);
    } else {
      index = binarySearch(nums, mid + 1, high, target);
    }

    return index;
  }

public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();

    int low = 0, high = n - 1;

    int ans = binarySearch(nums, low, high, target);

    return ans;
  }
};

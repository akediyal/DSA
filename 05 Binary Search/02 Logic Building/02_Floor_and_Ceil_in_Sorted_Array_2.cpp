class Solution {
private:
  int getFloor(vector<int> &nums, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] <= x) {
        ans = nums[mid];
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans;
  }

  int getCeil(vector<int> &nums, int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] >= x) {
        ans = nums[mid];
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

public:
  vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int n = nums.size();

    int floor = getFloor(nums, n, x);
    int ceil = getCeil(nums, n, x);

    return {floor, ceil};
  }
};

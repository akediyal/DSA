class Solution {
public:
  vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int n = nums.size();

    int floor = -1, ceil = -1;

    for (int i = 0; i < n; i++) {
      if (nums[i] <= x && nums[i] > floor) {
        floor = nums[i];
      }

      if (nums[i] >= x && (ceil == -1 || nums[i] < ceil)) {
        ceil = nums[i];
      }
    }

    return {floor, ceil};
  }
};

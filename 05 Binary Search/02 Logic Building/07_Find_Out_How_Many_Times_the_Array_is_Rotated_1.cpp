class Solution {
public:
  int findKRotation(vector<int> &nums) {
    int n = nums.size();

    int max_el = INT_MAX, ans = -1;

    for (int i = 0; i < n; i++) {
      if (nums[i] < max_el) {
        max_el = nums[i];
        ans = i;
      }
    }

    return ans;
  }
};

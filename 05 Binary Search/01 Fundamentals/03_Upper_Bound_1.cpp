class Solution {
public:
  int upperBound(vector<int> &nums, int x) {
    int n = nums.size();

    int ans = n;

    for (int i = 0; i < n; i++) {
      if (nums[i] > x) {
        ans = i;
        break;
      }
    }

    return ans;
  }
};

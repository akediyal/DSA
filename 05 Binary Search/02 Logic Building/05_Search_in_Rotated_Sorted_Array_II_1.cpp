class Solution {
public:
  bool searchInARotatedSortedArrayII(vector<int> &nums, int k) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == k) {
        return true;
      }
    }

    return false;
  }
};

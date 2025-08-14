class Solution {
public:
  int lowerBound(vector<int> &nums, int x) {
    int n = nums.size();

    int index = n;

    for (int i = 0; i < n; i++) {
      if (nums[i] >= x) {
        index = i;
        break;
      }
    }

    return index;
  }
};

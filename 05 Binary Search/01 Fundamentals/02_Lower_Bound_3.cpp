class Solution {
public:
  int lowerBound(vector<int> &nums, int x) {
    int n = nums.size();

    auto it = lower_bound(nums.begin(), nums.end(), x);

    if (it == nums.end()) {
      return n;
    }

    return it - nums.begin();
  }
};

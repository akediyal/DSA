class Solution {
public:
  void rotateArray(vector<int> &nums, int k) {
    int n = nums.size();

    int effective_rotations = k % n;

    if (effective_rotations == 0) {
      return;
    }

    reverse(nums.begin(), nums.begin() + effective_rotations);
    reverse(nums.begin() + effective_rotations, nums.end());
    reverse(nums.begin(), nums.end());
  }
};

class Solution {
public:
  void rotateArray(vector<int> &nums, int k) {
    int n = nums.size();
    int reduced_rotations = k % n;

    if (reduced_rotations == 0) {
      return;
    }

    while (reduced_rotations--) {
      int first_element = nums[0];

      for (int i = 1; i < n; i++) {
        nums[i - 1] = nums[i];
      }

      nums.back() = first_element;
    }
  }
};

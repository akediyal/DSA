class Solution {
public:
  void rotateArray(vector<int> &nums, int k) {
    int n = nums.size();

    int effective_rotations = k % n;

    if (effective_rotations == 0) {
      return;
    }

    vector<int> temp;

    for (int i = 0; i < effective_rotations; i++) {
      temp.push_back(nums[i]);
    }

    for (int i = effective_rotations; i < n; i++) {
      nums[i - effective_rotations] = nums[i];
    }

    for (int i = 0; i < temp.size(); i++) {
      nums[n - effective_rotations + i] = temp[i];
    }
  }
};

class Solution {
public:
  void rotateArrayByOne(vector<int> &nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
      int temp = nums[i - 1];
      nums[i - 1] = nums[i];
      nums[i] = temp;
    }
  }
};

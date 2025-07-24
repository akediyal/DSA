class Solution {
public:
  int largestElement(vector<int> &nums) {
    int max_element = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > max_element) {
        max_element = nums[i];
      }
    }

    return max_element;
  }
};

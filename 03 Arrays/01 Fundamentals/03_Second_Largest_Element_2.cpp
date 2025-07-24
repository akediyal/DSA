class Solution {
public:
  int secondLargestElement(vector<int> &nums) {
    // your code goes here
    int n = nums.size();

    if (n < 2) {
      return -1;
    }

    int max_element = nums[0];
    int sec_max_element = INT_MIN;

    for (int i = 1; i < n; i++) {
      if (nums[i] > max_element) {
        max_element = nums[i];
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] < max_element && nums[i] > sec_max_element) {
        sec_max_element = nums[i];
      }
    }

    return (sec_max_element == INT_MIN ? -1 : sec_max_element);
  }
};

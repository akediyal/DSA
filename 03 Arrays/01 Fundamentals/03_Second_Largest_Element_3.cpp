class Solution {
public:
  int secondLargestElement(vector<int> &nums) {
    // your code goes here
    int n = nums.size();

    int max_element = INT_MIN;
    int sec_max_element = INT_MIN;

    for (int i = 0; i < n; i++) {
      if (nums[i] > max_element) {
        sec_max_element = max_element;
        max_element = nums[i];
      } else if (nums[i] > sec_max_element && nums[i] < max_element) {
        sec_max_element = nums[i];
      }
    }

    return (sec_max_element == INT_MIN ? -1 : sec_max_element);
  }
};

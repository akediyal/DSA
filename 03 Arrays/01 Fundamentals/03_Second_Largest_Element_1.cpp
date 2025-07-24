class Solution {
public:
  int secondLargestElement(vector<int> &nums) {
    // your code goes here
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int max_element = nums[n - 1];
    int sec_max_element = -1;

    while (n >= 2) {

      if (nums[n - 2] < max_element) {
        sec_max_element = nums[n - 2];
        break;
      }

      n--;
    }

    return sec_max_element;
  }
};

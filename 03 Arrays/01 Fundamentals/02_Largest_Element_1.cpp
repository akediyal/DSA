class Solution {
public:
  int largestElement(vector<int> &nums) {
    int max_element = 0;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    max_element = nums[n - 1];

    return max_element;
  }
};

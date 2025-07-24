class Solution {
public:
  int linearSearch(vector<int> &nums, int target) {
    // your code goes here
    int target_index = -1;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        target_index = i;
        break;
      }
    }

    return target_index;
  }
};

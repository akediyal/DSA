class Solution {
public:
  vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();

    vector<int> positive_nums, negative_nums;

    for (int i = 0; i < n; i++) {
      if (nums[i] < 0) {
        negative_nums.push_back(nums[i]);
      } else {
        positive_nums.push_back(nums[i]);
      }
    }

    for (int i = 0; i < n / 2; i++) {
      nums[2 * i] = positive_nums[i];
      nums[2 * i + 1] = negative_nums[i];
    }

    return nums;
  }
};

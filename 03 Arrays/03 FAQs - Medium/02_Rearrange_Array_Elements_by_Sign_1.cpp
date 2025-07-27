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

    int i = 0, j = 0, k = 0;

    while (k < n) {
      if (k % 2 == 0 && i < positive_nums.size()) {
        nums[k] = positive_nums[i];
        i++;
      } else if (k % 2 == 1 && j < negative_nums.size()) {
        nums[k] = negative_nums[j];
        j++;
      }
      k++;
    }

    return nums;
  }
};

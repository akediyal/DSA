class Solution {
public:
  vector<int> insertionSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int key = nums[i];
      int j = i;

      while (j > 0 && nums[j - 1] > key) {
        nums[j] = nums[j - 1];
        j--;
      }

      nums[j] = key;
    }

    return nums;
  }
};

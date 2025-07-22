class Solution {
public:
  vector<int> selectionSort(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
      int min_index = i;

      for (int j = i; j < n; j++) {
        if (nums[j] < nums[min_index]) {
          min_index = j;
        }
      }

      int temp = nums[min_index];
      nums[min_index] = nums[i];
      nums[i] = temp;
    }

    return nums;
  }
};

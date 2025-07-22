class Solution {
public:
  vector<int> quickSort(vector<int> &nums) {
    qSort(nums, 0, nums.size() - 1);

    return nums;
  }

  void qSort(vector<int> &nums, int low, int high) {
    if (low < high) {
      int p_index = partition(nums, low, high);

      qSort(nums, low, p_index - 1);
      qSort(nums, p_index + 1, high);
    }
  }

  int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[low];
    int i = low, j = high;

    while (i < j) {

      while (nums[i] <= pivot && i < high) {
        i++;
      }

      while (nums[j] > pivot && j > low) {
        j--;
      }

      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }

    swap(nums[low], nums[j]);

    return j;
  }
};

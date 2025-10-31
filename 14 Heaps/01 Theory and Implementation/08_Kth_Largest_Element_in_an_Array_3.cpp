class Solution {
private:
  int randomIndex(int &left, int &right) {
    int len = right - left + 1;
    return (rand() % len) + left;
  }

  int partitionAndReturnIndex(vector<int> &nums, int pivot_index, int left,
                              int right) {
    int pivot = nums[pivot_index];
    swap(nums[left], nums[pivot_index]);
    int ind = left + 1;

    for (int i = left + 1; i <= right; i++) {
      if (nums[i] > pivot) {
        swap(nums[ind], nums[i]);
        ind++;
      }
    }

    swap(nums[left], nums[ind - 1]);

    return ind - 1;
  }

public:
  int kthLargestElement(vector<int> &nums, int k) {
    int n = nums.size();

    if (k > n) {
      return -1;
    }

    int left = 0, right = n - 1;

    while (true) {
      int pivot_index = randomIndex(left, right);
      pivot_index = partitionAndReturnIndex(nums, pivot_index, left, right);

      if (pivot_index == k - 1) {
        return nums[pivot_index];
      } else if (pivot_index > k - 1) {
        right = pivot_index - 1;
      } else {
        left = pivot_index + 1;
      }
    }

    return -1;
  }
};

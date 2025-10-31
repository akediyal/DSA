class Solution {
private:
  void heapifyDown(vector<int> &arr, int low, int high) {
    int largest_ind = low;
    int left_child_ind = 2 * low + 1;
    int right_child_ind = 2 * low + 2;

    if (left_child_ind <= high && arr[left_child_ind] > arr[largest_ind]) {
      largest_ind = left_child_ind;
    }

    if (right_child_ind <= high && arr[right_child_ind] > arr[largest_ind]) {
      largest_ind = right_child_ind;
    }

    if (largest_ind != low) {
      swap(arr[low], arr[largest_ind]);
      heapifyDown(arr, largest_ind, high);
    }
  }

  void buildMaxHeap(vector<int> &arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
      heapifyDown(arr, i, n - 1);
    }
  }

public:
  void heapSort(vector<int> &nums) {
    int n = nums.size();
    buildMaxHeap(nums);
    int last = n - 1;

    while (last > 0) {
      swap(nums[0], nums[last]);
      last--;
      heapifyDown(nums, 0, last);
    }
  }
};

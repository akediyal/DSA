class Solution {
private:
  void heapifyDown(vector<int> &arr, int ind) {
    int n = arr.size();
    int largest_ind = ind;
    int left_child_ind = 2 * ind + 1;
    int right_child_ind = 2 * ind + 2;

    if (left_child_ind < n && arr[left_child_ind] > arr[largest_ind]) {
      largest_ind = left_child_ind;
    }

    if (right_child_ind < n && arr[right_child_ind] > arr[largest_ind]) {
      largest_ind = right_child_ind;
    }

    if (largest_ind != ind) {
      swap(arr[ind], arr[largest_ind]);
      heapifyDown(arr, largest_ind);
    }
  }

public:
  vector<int> minToMaxHeap(vector<int> nums) {
    int n = nums.size();
    vector<int> arr = nums;

    for (int i = n / 2 - 1; i >= 0; i--) {
      heapifyDown(arr, i);
    }

    return arr;
  }
};

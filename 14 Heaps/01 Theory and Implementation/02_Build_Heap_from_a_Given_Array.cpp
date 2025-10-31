class Solution {
private:
  void heapifyDown(vector<int> &arr, int ind) {
    int n = arr.size();
    int smallest_ind = ind;
    int left_child_ind = 2 * ind + 1;
    int right_child_ind = 2 * ind + 2;

    if (left_child_ind < n && arr[left_child_ind] < arr[smallest_ind]) {
      smallest_ind = left_child_ind;
    }

    if (right_child_ind < n && arr[right_child_ind] < arr[smallest_ind]) {
      smallest_ind = right_child_ind;
    }

    if (smallest_ind != ind) {
      swap(arr[ind], arr[smallest_ind]);
      heapifyDown(arr, smallest_ind);
    }
  }

public:
  void buildMinHeap(vector<int> &nums) {
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
      heapifyDown(nums, i);
    }
  }
};

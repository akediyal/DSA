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

  void heapifyUp(vector<int> &arr, int ind) {
    int parent_ind = (ind - 1) / 2;

    if (ind > 0 && arr[ind] < arr[parent_ind]) {
      swap(arr[ind], arr[parent_ind]);
      heapifyUp(arr, parent_ind);
    }
  }

public:
  void heapify(vector<int> &nums, int ind, int val) {
    if (nums[ind] > val) {
      nums[ind] = val;
      heapifyUp(nums, ind);
    } else {
      nums[ind] = val;
      heapifyDown(nums, ind);
    }
  }
};

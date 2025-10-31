class Solution {
private:
  vector<int> arr;
  int count;

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
  void initializeHeap() {
    arr.clear();
    count = 0;
  }

  void insert(int key) {
    arr.push_back(key);
    heapifyUp(arr, count);
    count++;
  }

  void changeKey(int index, int new_val) {
    if (arr[index] > new_val) {
      arr[index] = new_val;
      heapifyUp(arr, index);
    } else {
      arr[index] = new_val;
      heapifyDown(arr, index);
    }
  }

  void extractMin() {
    int el = arr[0];
    swap(arr[0], arr[count - 1]);
    arr.pop_back();
    count--;
    heapifyDown(arr, 0);
  }

  bool isEmpty() { return count == 0; }

  int getMin() { return arr[0]; }

  int heapSize() { return count; }
};

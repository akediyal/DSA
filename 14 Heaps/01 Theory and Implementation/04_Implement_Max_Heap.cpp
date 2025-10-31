class Solution {
private:
  vector<int> arr;
  int count;

  void heapifyDown(int ind) {
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
      heapifyDown(largest_ind);
    }
  }

  void heapifyUp(int ind) {
    int parent_ind = (ind - 1) / 2;

    if (ind > 0 && arr[ind] > arr[parent_ind]) {
      swap(arr[ind], arr[parent_ind]);
      heapifyUp(parent_ind);
    }
  }

public:
  void initializeHeap() {
    arr.clear();
    count = 0;
  }

  void insert(int key) {
    arr.push_back(key);
    count++;
    heapifyUp(count - 1);
  }

  void changeKey(int index, int new_val) {
    if (arr[index] > new_val) {
      arr[index] = new_val;
      heapifyDown(index);
    } else {
      arr[index] = new_val;
      heapifyUp(index);
    }
  }

  void extractMax() {
    int el = arr[0];
    swap(arr[0], arr[count - 1]);
    arr.pop_back();
    count--;
    heapifyDown(0);
  }

  bool isEmpty() { return count == 0; }

  int getMax() { return arr[0]; }

  int heapSize() { return count; }
};

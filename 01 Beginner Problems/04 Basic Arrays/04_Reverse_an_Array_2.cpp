class Solution {
public:
  void reverse(int arr[], int n) {
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
      swap(arr[i], arr[j]);
    }
  }
};

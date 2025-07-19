class Solution {
public:
  void reverse(int arr[], int n) {
    int reverse_arr[n] = {0};

    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
      reverse_arr[j] = arr[i];
    }

    for (int i = 0; i < n; i++) {
      arr[i] = reverse_arr[i];
    }
  }
};

class Solution {
public:
  int countOdd(int arr[], int n) {
    int odd_num_count = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] % 2 == 1) {
        odd_num_count++;
      }
    }

    return odd_num_count;
  }
};

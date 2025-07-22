class Solution {
public:
  void pattern12(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < 2 * n; j++) {

        if (i >= j) {
          cout << j + 1;
        } else if (i + j >= 2 * n - 1) {
          cout << 2 * n - j;
        } else {
          cout << " ";
        }
      }

      cout << '\n';
    }
  }
};

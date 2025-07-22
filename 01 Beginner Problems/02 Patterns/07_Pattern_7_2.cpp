class Solution {
public:
  void pattern7(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < 2 * n - 1; j++) {

        if (i + j >= n - 1 && i >= j - (n - 1)) {
          cout << "*";
        } else {
          cout << " ";
        }
      }

      cout << '\n';
    }
  }
};

class Solution {
public:
  void pattern10(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {

      for (int j = 0; j < n; j++) {

        if (i >= j && i + j <= 2 * n - 2) {
          cout << "*";
        } else {
          cout << " ";
        }
      }

      cout << '\n';
    }
  }
};

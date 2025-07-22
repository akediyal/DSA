class Solution {
public:
  void pattern8(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < 2 * n - 1; j++) {

        if (i <= j && i + j <= 2 * n - 2) {
          cout << "*";
        } else {
          cout << " ";
        }
      }

      cout << '\n';
    }
  }
};

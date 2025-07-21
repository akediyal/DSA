class Solution {
public:
  void pattern19(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < n - i; j++) {
        cout << "*";
      }

      for (int j = 0; j < 2 * i; j++) {
        cout << " ";
      }

      for (int j = 0; j < n - i; j++) {
        cout << "*";
      }

      cout << '\n';
    }

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i + 1; j++) {
        cout << "*";
      }

      for (int j = 0; j < 2 * n - 2 * (i + 1); j++) {
        cout << " ";
      }

      for (int j = 0; j < i + 1; j++) {
        cout << "*";
      }

      cout << '\n';
    }
  }
};

class Solution {
public:
  void pattern10(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        cout << "*";
      }
      cout << '\n';
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j <= n - i - 1; j++) {
        cout << "*";
      }
      cout << '\n';
    }
  }
};

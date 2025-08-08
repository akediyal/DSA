class Solution {
public:
  void pattern13(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {

        if (i + j <= n - 1) {
          char c = j + 'A';
          cout << c;
        }
      }

      cout << '\n';
    }
  }
};

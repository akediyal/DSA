class Solution {
public:
  void pattern6(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < n; j++) {

        if (i + j <= n - 1) {
          cout << j + 1;
        } else {
          cout << " ";
        }
      }

      cout << '\n';
    }
  }
};

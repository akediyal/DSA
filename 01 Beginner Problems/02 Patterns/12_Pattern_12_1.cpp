class Solution {
public:
  void pattern12(int n) {
    for (int i = 0; i < n; i++) {
      int x = 1;

      for (int j = 0; j < i + 1; j++) {
        cout << x;
        x++;
      }

      for (int j = 0; j < 2 * n - 2 * (i + 1); j++) {
        cout << " ";
      }

      for (int j = 0; j < i + 1; j++) {
        cout << x - 1;
        x--;
      }

      cout << '\n';
    }
  }
};

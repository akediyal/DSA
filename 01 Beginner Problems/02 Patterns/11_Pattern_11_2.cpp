class Solution {
public:
  void pattern11(int n) {
    int x = 1;

    for (int i = 0; i < n; i++) {

      if (i % 2 == 0) {
        x = 1;
      } else {
        x = 0;
      }

      for (int j = 0; j < n; j++) {
        if (i >= j) {
          cout << x << " ";
          x = 1 - x;
        } else {
          cout << " ";
        }
      }

      cout << '\n';
    }
  }
};

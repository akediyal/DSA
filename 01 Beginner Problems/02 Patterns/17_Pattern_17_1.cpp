class Solution {
public:
  void pattern17(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < n - i - 1; j++) {
        cout << " ";
      }

      char c = 'A';

      for (int j = 0; j < 2 * i + 1; j++) {
        cout << c;
        if (j < i) {
          c++;
        } else {
          c--;
        }
      }

      for (int j = 0; j < n - i - 1; j++) {
        cout << " ";
      }

      cout << '\n';
    }
  }
};

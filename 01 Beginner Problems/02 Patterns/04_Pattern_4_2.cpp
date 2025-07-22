class Solution {
public:
  void pattern4(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < n; j++) {

        if (i >= j) {
          cout << i + 1;
        } else {
          cout << " ";
        }
      }

      cout << '\n';
    }
  }
};

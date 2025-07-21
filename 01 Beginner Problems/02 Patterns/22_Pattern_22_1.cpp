class Solution {
public:
  void pattern22(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {

      for (int j = 0; j < 2 * n - 1; j++) {

        int top = i, bottom = j;
        int left = (2 * n - 2) - i;
        int right = (2 * n - 2) - j;

        int ans = min(min(top, bottom), min(left, right));
        cout << n - ans << " ";
      }

      cout << '\n';
    }
  }
};

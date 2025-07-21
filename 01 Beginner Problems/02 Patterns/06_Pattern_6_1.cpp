class Solution {
public:
  void pattern6(int n) {
    for (int i = 0; i < n; i++) {
      int x = 1;
      for (int j = i; j < n; j++) {
        cout << x;
        x++;
      }
      cout << '\n';
    }
  }
};

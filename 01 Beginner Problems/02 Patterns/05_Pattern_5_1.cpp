class Solution {
public:
  void pattern5(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        cout << "*";
      }
      cout << '\n';
    }
  }
};

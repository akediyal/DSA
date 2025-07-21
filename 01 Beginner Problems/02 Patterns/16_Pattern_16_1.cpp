
class Solution {
public:
  void pattern16(int n) {
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i + 1; j++) {
        char c = i + 'A';
        cout << c;
      }

      cout << '\n';
    }
  }
};

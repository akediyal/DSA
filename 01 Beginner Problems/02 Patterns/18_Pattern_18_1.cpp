class Solution {
public:
  void pattern18(int n) {
    for (int i = 0; i < n; i++) {

      char initial_alphabet = 'A' + n - 1;
      for (char ch = initial_alphabet - i; ch < initial_alphabet + 1; ch++) {
        cout << ch << " ";
      }

      cout << '\n';
    }
  }
};

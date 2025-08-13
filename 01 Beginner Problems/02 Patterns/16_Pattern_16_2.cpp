class Solution {
public:
  void pattern16(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {

        if (i >= j) {
          char c = i + 'A';
          cout << c;
        } else
          cout << " ";
      }

      cout << endl;
    }
  }
};

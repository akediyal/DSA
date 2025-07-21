class Solution {
public:
  void pattern13(int n) {
    int reps = 0;
    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i + 1; j++) {
        reps++;
        cout << reps << " ";
      }

      cout << '\n';
    }
  }
};

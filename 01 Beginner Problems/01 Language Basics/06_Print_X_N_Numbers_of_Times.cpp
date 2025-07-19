class Solution {
public:
  void printX(int X, int N) {
    for (int i = 0; i < N; i++) {
      cout << X << " "[i == N - 1];
    }
    cout << '\n';
  }
};

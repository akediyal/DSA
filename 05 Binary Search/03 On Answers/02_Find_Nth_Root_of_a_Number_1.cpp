class Solution {
public:
  int NthRoot(int N, int M) {
    long long ans = -1;

    for (int i = 1; i <= M; i++) {
      long long val = pow(i, N);

      if (val == M * 1LL) {
        ans = i;
      } else if (val > M * 1LL) {
        break;
      }
    }

    return ans;
  }
};

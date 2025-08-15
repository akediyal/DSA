class Solution {
private:
  long long powExp(int num, int exp) {
    long long ans = 1;
    long long base = num;

    while (exp > 0) {
      if (exp % 2) {
        exp--;
        ans *= base;
      } else {
        exp /= 2;
        base *= base;
      }
    }

    return ans;
  }

public:
  int NthRoot(int N, int M) {
    long long ans = -1;

    for (int i = 1; i <= M; i++) {
      long long val = powExp(i, N);

      if (val == M * 1LL) {
        ans = i;
      } else if (val > M * 1LL) {
        break;
      }
    }

    return ans;
  }
};

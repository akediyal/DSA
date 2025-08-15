class Solution {
private:
  long long checker(int N, int M, int mid) {
    long long ans = 1;
    long long base = mid;

    while (N > 0) {
      if (N % 2) {
        ans *= base;

        if (ans > M) {
          return 2;
        }

        N--;
      } else {
        N /= 2;
        base *= base;

        if (base > M) {
          return 2;
        }
      }
    }

    if (ans == M) {
      return 1;
    }

    return 0;
  }

public:
  int NthRoot(int N, int M) {
    int low = 1, high = M;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int mid_N = checker(N, M, mid);

      if (mid_N == 1) {
        return mid;
      } else if (mid_N == 0) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return -1;
  }
};

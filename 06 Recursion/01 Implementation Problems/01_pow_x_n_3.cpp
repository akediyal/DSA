class Solution {
public:
  double myPow(double x, int n) {
    if (x == 1.0 || n == 0) {
      return 1;
    }

    long long num = n;

    if (n < 0) {
      x = 1 / x;
      num = -1 * n * 1LL;
    }

    if (num == 1) {
      return x;
    }

    if (num % 2 == 1) {
      return x * myPow(x, num - 1);
    }

    return myPow(x * x, num / 2);
  }
};

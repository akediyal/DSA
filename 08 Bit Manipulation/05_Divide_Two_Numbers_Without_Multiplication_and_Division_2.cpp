class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == divisor) {
      return 1;
    }

    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    if (divisor == 1) {
      return dividend;
    }

    bool sign =
        !((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0));

    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);

    long long ans = 0;

    while (n >= d) {
      int cnt = 0;

      while (n >= (d << (cnt + 1))) {
        cnt++;
      }

      ans += (1 << cnt);
      n -= d * (1 << cnt);
    }

    if (ans > INT_MAX) {
      return (sign ? INT_MAX : INT_MIN);
    }

    return (sign ? ans : -ans);
  }
};

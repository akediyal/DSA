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

    bool sign = true;

    if ((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
      sign = false;
    }

    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);

    long long ans = 0, sum = 0;

    while (sum + d <= n) {
      ans++;
      sum += d;
    }

    if (ans > INT_MAX && sign == true) {
      return INT_MAX;
    }

    if (ans > INT_MAX && sign == false) {
      return INT_MIN;
    }

    return (sign ? ans : -ans);
  }
};

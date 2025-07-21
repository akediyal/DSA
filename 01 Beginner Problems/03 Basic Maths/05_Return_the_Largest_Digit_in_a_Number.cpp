class Solution {
public:
  int largestDigit(int n) {
    int rem = 0, mx = 0;

    while (n != 0) {
      rem = n % 10;
      mx = max(mx, rem);
      n /= 10;
    }

    return mx;
  }
};

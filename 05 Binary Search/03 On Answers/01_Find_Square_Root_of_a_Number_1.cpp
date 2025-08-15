class Solution {
public:
  long long floorSqrt(long long n) {
    long long ans = 0;

    for (long long i = 1; i <= n; i++) {
      if (i * i <= n * 1LL) {
        ans = i;
      } else {
        break;
      }
    }

    return ans;
  }
};

class Solution {
public:
  long long floorSqrt(long long n) {
    int ans = 0;

    int low = 1, high = n;

    while (low <= high) {
      long long mid = low + (high - low) / 2;
      long long val = mid * mid;

      if (val <= n) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans;
  }
};

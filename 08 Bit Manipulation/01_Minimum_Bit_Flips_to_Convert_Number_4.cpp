class Solution {
public:
  int minBitsFlip(int start, int goal) {
    int n = start ^ goal;
    int ans = __builtin_popcount(n);

    return ans;
  }
};

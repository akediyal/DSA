class Solution {
public:
  int findRangeXOR(int l, int r) {
    int ans = 0;

    for (int i = l; i <= r; i++) {
      ans ^= i;
    }

    return ans;
  }
};

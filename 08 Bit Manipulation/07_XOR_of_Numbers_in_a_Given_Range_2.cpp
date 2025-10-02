class Solution {
private:
  int XORtillN(int n) {
    if (n % 4 == 1) {
      return 1;
    } else if (n % 4 == 2) {
      return n + 1;
    } else if (n % 4 == 3) {
      return 0;
    } else {
      return n;
    }
  }

public:
  int findRangeXOR(int l, int r) {
    int ans = XORtillN(l - 1) ^ XORtillN(r);
    return ans;
  }
};

class Solution {
public:
  int countDigit(int n) {
    if (n == 0) {
      return 1;
    }
    int count = log10(n) + 1;
    return count;
  }
};

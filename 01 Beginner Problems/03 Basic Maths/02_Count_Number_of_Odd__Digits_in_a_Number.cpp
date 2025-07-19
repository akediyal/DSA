class Solution {
public:
  int countOddDigit(int n) {
    if (n == 0) {
      return 0;
    }

    int count = 0, rem = 0;
    while (n != 0) {
      rem = n % 10;
      if (n % 2 == 1) {
        count++;
      }
      n /= 10;
    }

    return count;
  }
};

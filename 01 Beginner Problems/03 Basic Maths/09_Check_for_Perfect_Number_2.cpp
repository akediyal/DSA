class Solution {
public:
  bool isPerfect(int n) {
    int divSum = 0;

    for (int i = 1; i * i < n; i++) {
      if (n % i == 0) {
        divSum += i;

        if (i != n / i && i != 1) {
          divSum += n / i;
        }
      }
    }

    if (divSum == n) {
      return true;
    } else {
      return false;
    }
  }
};

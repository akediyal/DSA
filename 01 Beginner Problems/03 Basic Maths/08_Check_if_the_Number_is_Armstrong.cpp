class Solution {
public:
  bool isArmstrong(int n) {
    int rem = 0, original_num = n;
    int armstrong_num = 0;

    int total_digits = log10(n) + 1;

    while (n != 0) {
      rem = n % 10;
      armstrong_num += pow(rem, total_digits);
      n /= 10;
    }

    if (armstrong_num == original_num) {
      return true;
    } else {
      return false;
    }
  }
};

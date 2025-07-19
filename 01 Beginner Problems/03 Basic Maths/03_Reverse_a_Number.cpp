class Solution {
public:
  int reverseNumber(int n) {
    int rem = 0;
    int reversed_num = 0;

    while (n != 0) {
      rem = n % 10;
      reversed_num = reversed_num * 10 + rem;
      n /= 10;
    }

    return reversed_num;
  }
};

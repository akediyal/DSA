class Solution {
public:
  bool isPalindrome(int n) {
    int original_num = n;
    int reversed_num = 0, rem = 0;

    while (n != 0) {
      rem = n % 10;
      reversed_num = reversed_num * 10 + rem;
      n /= 10;
    }

    return reversed_num == original_num;
  }
};

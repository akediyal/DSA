class Solution {
public:
  bool checkPrime(int num) {
    // your code goes here
    return isPrime(num, 2);
  }
  bool isPrime(int num, int cur) {
    if (num < 2) {
      return false;
    }
    if (cur * cur > num) {
      return true;
    }
    if (num % cur == 0) {
      return false;
    }
    return isPrime(num, cur + 1);
  }
};

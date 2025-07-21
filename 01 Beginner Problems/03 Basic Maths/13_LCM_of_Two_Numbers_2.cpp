class Solution {
public:
  int LCM(int n1, int n2) {
    int product = n1 * n2;
    int gcd = GCD(n1, n2);
    int lcm = product / gcd;
    return lcm;
  }

  int GCD(int n1, int n2) {
    int gcd = 1;

    while (n1 > 0 && n2 > 0) {
      if (n1 > n2) {
        n1 %= n2;
      } else {
        n2 %= n1;
      }
    }

    return (n1 == 0 ? n2 : n1);
  }
};

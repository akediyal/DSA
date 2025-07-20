class Solution {
public:
  int addDigits(int num) {
    int _ = num;
    while (_ / 10 != 0) {
      _ = solve(_);
    }
    return _;
  }

  int solve(int num) {
    if (num / 10 == 0)
      return num;

    return num % 10 + solve(num / 10);
  }
};

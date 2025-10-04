class Solution {
public:
  bool isValid(string s) {
    int min = 0, max = 0;

    for (char c : s) {
      if (c == '(') {
        min += 1;
        max += 1;
      } else if (c == ')') {
        min -= 1;
        max -= 1;
      } else {
        min -= 1;
        max += 1;
      }

      if (max < 0) {
        return false;
      }

      if (min < 0) {
        min = 0;
      }
    }

    return (min == 0);
  }
};

class Solution {
public:
  string largeOddNum(string &s) {
    // your code goes here
    int index = s.size() - 1;

    while (index >= 0 && (s[index] - '0') % 2 == 0) {
      index--;
    }

    int i = 0;
    while (i <= index && s[i] == '0') {
      i++;
    }

    return s.substr(i, index - i + 1);
  }
};

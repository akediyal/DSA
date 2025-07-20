class Solution {
public:
  bool palindromeCheck(string &s) {
    // your code goes here
    string str = reverseString(s, s.size() - 1);
    return str == s;
  }
  string reverseString(string &s, int cur) {
    if (cur < 0) {
      return "";
    }
    return s[cur] + reverseString(s, cur - 1);
  }
};

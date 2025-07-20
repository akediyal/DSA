class Solution {
public:
  vector<char> reverseString(vector<char> &s) {
    // your code goes here
    vector<char> str;
    reverse(s, s.size() - 1, str);
    return str;
  }
  void reverse(vector<char> &s, int cur, vector<char> &str) {
    if (cur < 0) {
      return;
    }
    str.push_back(s[cur]);
    return reverse(s, cur - 1, str);
  }
};

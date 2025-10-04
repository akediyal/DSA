class Solution {
private:
  bool helperFunc(string s, int idx, int cnt) {
    int n = s.size();

    if (cnt < 0) {
      return false;
    }

    if (idx == n) {
      return (cnt == 0);
    }

    if (s[idx] == '(') {
      return helperFunc(s, idx + 1, cnt + 1);
    } else if (s[idx] == ')') {
      return helperFunc(s, idx + 1, cnt - 1);
    }

    return helperFunc(s, idx + 1, cnt + 1) || helperFunc(s, idx + 1, cnt - 1) ||
           helperFunc(s, idx + 1, cnt);
  }

public:
  bool isValid(string s) {
    bool ans = helperFunc(s, 0, 0);
    return ans;
  }
};

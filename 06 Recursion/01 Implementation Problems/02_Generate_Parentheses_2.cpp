class Solution {
private:
  void helperFunc(int open, int close, int n, string s, vector<string> &ans) {
    if (open == close && (open + close) == 2 * n) {
      ans.push_back(s);
      return;
    }

    if (open < n) {
      helperFunc(open + 1, close, n, s + '(', ans);
    }

    if (close < open) {
      helperFunc(open, close + 1, n, s + ')', ans);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;

    helperFunc(0, 0, n, "", ans);

    return ans;
  }
};

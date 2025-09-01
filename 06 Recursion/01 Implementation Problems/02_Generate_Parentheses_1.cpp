class Solution {
private:
  void helperFunc(int idx, string s, int open, int close, vector<string> &ans,
                  int n) {
    if (open > n) {
      return;
    }

    if (open == close && (open + close) == 2 * n) {
      ans.push_back(s);
      return;
    }

    helperFunc(idx + 1, s + '(', open + 1, close, ans, n);

    if (open > close) {
      helperFunc(idx + 1, s + ')', open, close + 1, ans, n);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;

    helperFunc(0, "", 1, 0, ans, n);

    return ans;
  }
};

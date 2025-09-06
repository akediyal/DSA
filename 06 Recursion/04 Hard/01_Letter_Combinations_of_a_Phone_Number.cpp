class Solution {
private:
  void helperFunc(int idx, string s, string digits, vector<string> combos,
                  vector<string> &ans) {
    if (idx == digits.size()) {
      ans.push_back(s);
      return;
    }

    int digit = digits[idx] - '0';

    for (int i = 0; i < combos[digit].size(); i++) {
      helperFunc(idx + 1, s + combos[digit][i], digits, combos, ans);
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    vector<string> combos = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string s = "";

    helperFunc(0, s, digits, combos, ans);

    return ans;
  }
};

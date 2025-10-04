class Solution {
private:
  bool checkValid(int ind, int count, string &s, vector<vector<int>> &dp) {
    int n = s.size();

    if (count < 0) {
      return false;
    }

    if (ind == n) {
      return (count == 0);
    }

    if (dp[ind][count] != -1) {
      return dp[ind][count];
    }

    bool ans = false;

    if (s[ind] == '(') {
      ans = checkValid(ind + 1, count + 1, s, dp);
    } else if (s[ind] == ')') {
      ans = checkValid(ind + 1, count - 1, s, dp);
    } else {
      for (int i = -1; i <= 1; i++) {
        ans = ans || checkValid(ind + 1, count + i, s, dp);
      }
    }

    return (dp[ind][count] = ans);
  }

public:
  bool isValid(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return checkValid(0, 0, s, dp);
  }
};

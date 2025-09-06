class Solution {
private:
  bool isPalindrome(string s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }

      left++, right--;
    }

    return true;
  }

  void helperFunc(int idx, vector<string> &arr, string s,
                  vector<vector<string>> &ans) {
    int n = s.size();

    if (idx == n) {
      ans.push_back(arr);
      return;
    }

    for (int i = idx; i < n; i++) {
      if (isPalindrome(s, idx, i)) {
        string substr = s.substr(idx, i - idx + 1);

        arr.push_back(substr);
        helperFunc(i + 1, arr, s, ans);
        arr.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> arr;

    helperFunc(0, arr, s, ans);

    return ans;
  }
};

class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    int min_len = INT_MAX;
    int s_index = -1;
    int hash[256] = {0};

    for (int i = 0; i < m; i++) {
      hash[t[i]]++;
    }

    int cnt = 0;
    int l = 0, r = 0;

    while (r < n) {
      if (hash[s[r]] > 0) {
        cnt++;
      }

      hash[s[r]]--;

      while (cnt == m) {
        if (r - l + 1 < min_len) {
          min_len = r - l + 1;
          s_index = l;
        }

        hash[s[l]]++;

        if (hash[s[l]] > 0) {
          cnt--;
        }

        l++;
      }

      r++;
    }

    return ((s_index == -1) ? "" : s.substr(s_index, min_len));
  }
};

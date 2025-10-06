class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    int min_len = INT_MAX;
    int s_index = -1;

    for (int i = 0; i < n; i++) {
      int hash[256] = {0};

      for (int j = 0; j < m; j++) {
        hash[t[j]]++;
      }

      int cnt = 0;

      for (int j = i; j < n; j++) {
        if (hash[s[j]] > 0) {
          cnt++;
        }

        hash[s[j]]--;

        if (cnt == m) {
          if (j - i + 1 < min_len) {
            min_len = j - i + 1;
            s_index = i;
          }
          break;
        }
      }
    }

    if (s_index == -1) {
      return "";
    }

    return s.substr(s_index, min_len);
  }
};

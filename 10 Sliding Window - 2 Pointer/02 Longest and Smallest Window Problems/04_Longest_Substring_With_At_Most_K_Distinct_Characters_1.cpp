class Solution {
public:
  int kDistinctChar(string &s, int k) {
    int n = s.size();
    unordered_map<char, int> mp;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
      mp.clear();

      for (int j = i; j < n; j++) {
        mp[s[j]]++;

        if (mp.size() > k) {
          break;
        } else {
          int len = j - i + 1;
          max_len = max(max_len, len);
        }
      }
    }

    return max_len;
  }
};

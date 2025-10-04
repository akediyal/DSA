class Solution {
public:
  int kDistinctChar(string &s, int k) {
    int n = s.size();
    unordered_map<char, int> mp;
    int max_len = 0;
    int l = 0, r = 0;

    while (r < n) {
      mp[s[r]]++;

      if (mp.size() > k) {
        mp[s[l]]--;

        if (mp[s[l]] == 0) {
          mp.erase(s[l]);
        }

        l++;
      }

      if (mp.size() <= k) {
        int len = r - l + 1;
        max_len = max(max_len, len);
      }

      r++;
    }

    return max_len;
  }
};

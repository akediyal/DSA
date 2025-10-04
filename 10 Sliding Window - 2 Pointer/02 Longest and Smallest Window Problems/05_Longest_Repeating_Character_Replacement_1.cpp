class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    int max_len = 0;
    int max_freq = 0;

    for (int i = 0; i < n; i++) {
      int hash[26] = {0};

      for (int j = i; j < n; j++) {
        hash[s[j] - 'A']++;
        max_freq = max(max_freq, hash[s[j] - 'A']);
        int changes = (j - i + 1) - max_freq;

        if (changes <= k) {
          int len = j - i + 1;
          max_len = max(max_len, len);
        } else {
          break;
        }
      }
    }

    return max_len;
  }
};

class Solution {
public:
  bool anagramStrings(string &s, string t) {
    // your code goes here
    if (s.size() != t.size()) {
      return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
      freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
      if (freq[i] != 0) {
        return false;
      }
    }

    return true;
  }
};

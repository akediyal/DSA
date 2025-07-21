class Solution {
public:
  bool anagramStrings(string &s, string t) {
    // your code goes here
    unordered_map<int, int> freq;
    for (int i = 0; i < s.size(); i++) {
      freq[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++) {
      freq[t[i]]--;
    }

    for (auto i : freq) {
      if (i.second != 0) {
        return false;
      }
    }

    return true;
  }
};

class Solution {
public:
  bool anagramStrings(string &s, string t) {
    // your code goes here
    if (s.size() != t.size()) {
      return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
  }
};

class Solution {
public:
  bool isomorphicString(string s, string t) {
    // your code goes here
    int map_s[256] = {0}, map_t[256] = {0};

    for (int i = 0; i < s.size(); i++) {

      if (map_s[s[i]] != map_t[t[i]]) {
        return false;
      }

      map_s[s[i]] = i + 1;
      map_t[t[i]] = i + 1;
    }

    return true;
  }
};

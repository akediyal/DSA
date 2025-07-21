class Solution {
public:
  bool rotateString(string &s, string &goal) {
    // your code goes here
    if (s.size() != goal.size()) {
      return false;
    }

    for (int i = 0; i < s.size(); i++) {
      string rotated_str = s.substr(i, s.size()) + s.substr(0, i);
      if (rotated_str == goal) {
        return true;
      }
    }

    return false;
  }
};

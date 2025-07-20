class Solution {
public:
  vector<char> reverseString(vector<char> &s) {
    // your code goes here
    reverse(s, 0, s.size() - 1);
    return s;
  }

  void reverse(vector<char> &s, int left, int right) {
    if (left >= right) {
      return;
    }
    swap(s[left], s[right]);
    return reverse(s, left + 1, right - 1);
  }
};

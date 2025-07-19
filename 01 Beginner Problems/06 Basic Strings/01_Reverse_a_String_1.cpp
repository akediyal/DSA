class Solution {
public:
  void reverseString(vector<char> &s) {
    // your code goes here
    stack<char> stack;

    for (char c : s) {
      stack.push(c);
    }

    for (int i = 0; i < s.size(); i++) {
      s[i] = stack.top();
      stack.pop();
    }
  }
};

class Solution {
public:
  bool palindromeCheck(string &s) {
    // your code goes here
    stack<char> stack;
    for (char c : s) {
      stack.push(c);
    }

    string reverse_str;
    for (int i = 0; i < s.size(); i++) {
      reverse_str.push_back(stack.top());
      stack.pop();
    }

    return reverse_str == s;
  }
};

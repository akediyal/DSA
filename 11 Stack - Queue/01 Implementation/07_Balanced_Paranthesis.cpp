class Solution {
private:
  bool isMatched(char open, char close) {
    if ((open == '(' && close == ')') || (open == '{' && close == '}') ||
        (open == '[' && close == ']')) {
      return true;
    }

    return false;
  }

public:
  bool isValid(string str) {
    int n = str.size();
    stack<char> st;

    for (int i = 0; i < n; i++) {
      if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
        st.push(str[i]);
      } else {
        if (st.empty()) {
          return false;
        }

        char open = st.top();
        st.pop();

        if (!isMatched(open, str[i])) {
          return false;
        }
      }
    }

    return st.empty();
  }
};

class Solution {
public:
  string removeKdigits(string nums, int k) {
    int n = nums.size();
    stack<char> st;

    for (int i = 0; i < n; i++) {
      char digit = nums[i];

      while (!st.empty() && k > 0 && st.top() > digit) {
        st.pop();
        k--;
      }

      st.push(digit);
    }

    while (!st.empty() && k > 0) {
      st.pop();
      k--;
    }

    if (st.empty()) {
      return "0";
    }

    string ans = "";

    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    while (ans.size() > 0 && ans.back() == '0') {
      ans.pop_back();
    }

    if (ans.empty()) {
      return "0";
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

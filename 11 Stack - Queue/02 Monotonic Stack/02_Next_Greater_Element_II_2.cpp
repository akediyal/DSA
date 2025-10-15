class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
      int index = i % n;
      int cur_el = arr[index];

      while (!st.empty() && st.top() <= cur_el) {
        st.pop();
      }

      if (i < n) {
        if (st.empty()) {
          ans[i] = -1;
        } else {
          ans[i] = st.top();
        }
      }

      st.push(cur_el);
    }

    return ans;
  }
};

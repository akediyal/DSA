class Solution {
private:
  vector<int> findPGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      int cur_el = arr[i];

      while (!st.empty() && arr[st.top()] <= cur_el) {
        st.pop();
      }

      ans[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    return ans;
  }

public:
  vector<int> stockSpan(vector<int> arr, int n) {
    vector<int> pge = findPGE(arr);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
      ans[i] = i - pge[i];
    }

    return ans;
  }
};

class Solution {
public:
  int celebrity(vector<vector<int>> &M) {
    int n = M.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
      st.push(i);
    }

    while (st.size() >= 2) {
      int p1 = st.top();
      st.pop();
      int p2 = st.top();
      st.pop();

      if (M[p1][p2] == 1) {
        st.push(p2);
      } else {
        st.push(p1);
      }
    }

    int candidate = st.top();

    for (int i = 0; i < n; i++) {
      if (i == candidate) {
        continue;
      }

      if (M[candidate][i] == 1 || M[i][candidate] == 0) {
        return -1;
      }
    }

    return candidate;
  }
};

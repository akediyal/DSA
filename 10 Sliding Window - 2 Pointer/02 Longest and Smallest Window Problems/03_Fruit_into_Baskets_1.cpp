class Solution {
public:
  int totalFruits(vector<int> &fruits) {
    int n = fruits.size();
    int max_len = 0;

    for (int i = 0; i < n; i++) {
      unordered_set<int> st;

      for (int j = i; j < n; j++) {
        st.insert(fruits[j]);

        if (st.size() > 2) {
          break;
        } else {
          int len = j - i + 1;
          max_len = max(max_len, len);
        }
      }
    }

    return max_len;
  }
};

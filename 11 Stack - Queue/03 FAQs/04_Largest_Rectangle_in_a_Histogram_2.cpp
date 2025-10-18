class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> st;
    int largest_area = 0;
    int area = -1;
    int nse, pse;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        int idx = st.top();
        st.pop();

        pse = st.empty() ? -1 : st.top();
        nse = i;

        area = heights[idx] * (nse - pse - 1);
        largest_area = max(largest_area, area);
      }

      st.push(i);
    }

    while (!st.empty()) {
      int idx = st.top();
      st.pop();

      nse = n;
      pse = st.empty() ? -1 : st.top();

      area = heights[idx] * (nse - pse - 1);
      largest_area = max(largest_area, area);
    }

    return largest_area;
  }
};

class Solution {
private:
  vector<int> findPSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      int cur_el = arr[i];

      while (!st.empty() && arr[st.top()] >= cur_el) {
        st.pop();
      }

      ans[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    return ans;
  }

  vector<int> findNSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
      int cur_el = arr[i];

      while (!st.empty() && arr[st.top()] >= arr[i]) {
        st.pop();
      }

      ans[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    return ans;
  }

public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> pse = findPSE(heights);
    vector<int> nse = findNSE(heights);
    int largest_area = -1;
    int area = -1;

    for (int i = 0; i < n; i++) {
      area = heights[i] * (nse[i] - pse[i] - 1);
      largest_area = max(largest_area, area);
    }

    return largest_area;
  }
};

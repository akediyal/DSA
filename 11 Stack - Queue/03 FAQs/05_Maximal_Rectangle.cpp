class Solution {
private:
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

public:
  int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> prefix_sum(rows, vector<int>(cols, -1));

    for (int j = 0; j < cols; j++) {
      int sum = 0;

      for (int i = 0; i < rows; i++) {
        sum += matrix[i][j];

        if (matrix[i][j] == 0) {
          sum = 0;
        }

        prefix_sum[i][j] = sum;
      }
    }

    int max_area = 0;

    for (int i = 0; i < rows; i++) {
      int area = largestRectangleArea(prefix_sum[i]);
      max_area = max(max_area, area);
    }

    return max_area;
  }
};

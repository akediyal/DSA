class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && height[i] > height[st.top()]) {
        int mid = st.top();
        st.pop();

        if (st.empty()) {
          break;
        }

        int left = st.top();
        int width = i - left - 1;
        int val = min(height[i], height[left]) - height[mid];
        ans += width * val;
      }

      st.push(i);
    }

    return ans;
  }
};

class Solution {
private:
  int getLeftMax(vector<int> &height, int x) {
    int n = height.size();
    int left_max = -1;

    for (int i = x; i >= 0; i--) {
      left_max = max(left_max, height[i]);
    }

    return left_max;
  }

  int getRightMax(vector<int> &height, int x) {
    int n = height.size();
    int right_max = -1;

    for (int i = x; i < n; i++) {
      right_max = max(right_max, height[i]);
    }

    return right_max;
  }

public:
  int trap(vector<int> &height) {
    int n = height.size();
    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
      int left_max = getLeftMax(height, i);
      int right_max = getRightMax(height, i);

      if (height[i] < left_max && height[i] < right_max) {
        ans += min(left_max, right_max) - height[i];
      }
    }

    return ans;
  }
};

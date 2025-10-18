class Solution {
private:
  vector<int> getSuffixMaxArray(vector<int> &height) {
    int n = height.size();
    vector<int> suffix_max(n);
    suffix_max[n - 1] = height[n - 1];

    for (int i = n - 2; i >= 0; i--) {
      suffix_max[i] = max(suffix_max[i + 1], height[i]);
    }

    return suffix_max;
  }

public:
  int trap(vector<int> &height) {
    int n = height.size();

    if (n <= 2) {
      return 0;
    }

    int ans = 0;
    int left_max = height[0];
    vector<int> right_max = getSuffixMaxArray(height);

    for (int i = 1; i < n - 1; i++) {
      left_max = max(left_max, height[i]);
      int val = min(left_max, right_max) - height[i];
      ans += max(0, val);
    }

    return ans;
  }
};

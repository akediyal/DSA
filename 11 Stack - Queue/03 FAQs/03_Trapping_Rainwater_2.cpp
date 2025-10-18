class Solution {
private:
  vector<int> getPrefixMaxArray(vector<int> &height) {
    int n = height.size();
    vector<int> prefix_max(n);
    prefix_max[0] = height[0];

    for (int i = 1; i < n; i++) {
      prefix_max[i] = max(prefix_max[i - 1], height[i]);
    }

    return prefix_max;
  }

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
    int ans = 0;

    vector<int> left_max = getPrefixMaxArray(height);
    vector<int> right_max = getSuffixMaxArray(height);

    for (int i = 1; i < n - 1; i++) {
      if (height[i] < left_max[i] && height[i] < right_max[i]) {
        ans += min(left_max[i], right_max[i]) - height[i];
      }
    }

    return ans;
  }
};

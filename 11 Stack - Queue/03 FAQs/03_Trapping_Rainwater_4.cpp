class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int ans = 0;
    int left_max = 0;
    int right_max = 0;
    int left = 0, right = n - 1;

    while (left < right) {
      if (height[left] <= height[right]) {
        if (left_max > height[left]) {
          ans += left_max - height[left];
        } else {
          left_max = height[left];
        }
        left++;
      }

      else {
        if (right_max > height[right]) {
          ans += right_max - height[right];
        } else {
          right_max = height[right];
        }
        right--;
      }
    }

    return ans;
  }
};

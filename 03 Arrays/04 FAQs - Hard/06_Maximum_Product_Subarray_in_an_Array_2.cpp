class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();

    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
      int product = 1;

      for (int j = i; j < n; j++) {
        product *= nums[j];
        ans = max(ans, product);
      }

      ans = max(ans, product);
    }

    return ans;
  }
};

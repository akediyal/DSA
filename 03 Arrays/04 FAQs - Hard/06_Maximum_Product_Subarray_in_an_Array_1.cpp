class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();

    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int product = 1;

        for (int k = i; k <= j; k++) {
          product = product * nums[k];
        }

        ans = max(ans, product);
      }
    }

    return ans;
  }
};

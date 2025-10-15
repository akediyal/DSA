class Solution {
public:
  int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    int mod = 1e9 + 7;
    int sum = 0;

    for (int i = 0; i < n; i++) {
      int mn = arr[i];

      for (int j = i; j < n; j++) {
        mn = min(mn, arr[j]);
        sum = (sum + mn) % mod;
      }
    }

    return sum;
  }
};

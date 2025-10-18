class Solution {
public:
  vector<int> stockSpan(vector<int> arr, int n) {
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
      int cur_span = 0;

      for (int j = i; j >= 0; j--) {
        if (arr[j] <= arr[i]) {
          cur_span++;
        } else {
          break;
        }
      }

      ans[i] = cur_span;
    }

    return ans;
  }
};

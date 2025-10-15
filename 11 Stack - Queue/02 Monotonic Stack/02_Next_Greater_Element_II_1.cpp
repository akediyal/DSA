class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < i + n; j++) {
        int index = j % n;

        if (arr[index] > arr[i]) {
          ans[i] = arr[index];
          break;
        }
      }
    }

    return ans;
  }
};

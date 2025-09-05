class Solution {
private:
  void helperFunc(int sum, vector<int> &arr, vector<vector<int>> &ans, int k) {
    if (sum == 0 && arr.size() == k) {
      ans.push_back(arr);
      return;
    }

    if (sum < 0 || arr.size() > k) {
      return;
    }

    int element = arr.empty() ? 1 : arr.back() + 1;

    for (int i = element; i <= 9; i++) {
      if (i <= sum) {
        arr.push_back(i);
        helperFunc(sum - i, arr, ans, k);
        arr.pop_back();
      } else {
        break;
      }
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> arr;

    helperFunc(n, arr, ans, k);

    return ans;
  }
};

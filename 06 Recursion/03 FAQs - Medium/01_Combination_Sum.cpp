class Solution {
private:
  void helperFunc(vector<int> &candidates, int idx, vector<int> &arr, int sum,
                  vector<vector<int>> &ans) {
    if (sum == 0) {
      ans.push_back(arr);
      return;
    }

    if (sum < 0 || idx == candidates.size()) {
      return;
    }

    arr.push_back(candidates[idx]);
    helperFunc(candidates, idx, arr, sum - candidates[idx], ans);
    arr.pop_back();

    helperFunc(candidates, idx + 1, arr, sum, ans);
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> arr;

    helperFunc(candidates, 0, arr, target, ans);

    return ans;
  }
};

class Solution {
private:
  void helperFunc(int idx, vector<vector<int>> &ans, vector<int> &arr,
                  vector<int> &candidates, int sum) {
    if (sum == 0) {
      ans.push_back(arr);
      return;
    }

    if (sum < 0 || idx == candidates.size()) {
      return;
    }

    arr.push_back(candidates[idx]);
    helperFunc(idx + 1, ans, arr, candidates, sum - candidates[idx]);
    arr.pop_back();

    for (int i = idx + 1; i < candidates.size(); i++) {
      if (candidates[i] != candidates[idx]) {
        helperFunc(i, ans, arr, candidates, sum);
        break;
      }
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> arr;

    sort(candidates.begin(), candidates.end());

    helperFunc(0, ans, arr, candidates, target);

    return ans;
  }
};

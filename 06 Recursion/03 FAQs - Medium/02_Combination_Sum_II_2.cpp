class Solution {
private:
  int upperBound(vector<int> &candidates, int start_idx, int x) {
    int n = candidates.size();

    int low = start_idx, high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (candidates[mid] > x) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

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

    int next_idx = upperBound(candidates, idx + 1, candidates[idx]);

    helperFunc(next_idx, ans, arr, candidates, sum);
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

class Solution {
private:
  void helperFunc(int idx, vector<int> &arr, vector<int> &nums,
                  vector<vector<int>> &ans) {
    int n = nums.size();

    if (idx == n) {
      ans.push_back(arr);
      return;
    }

    arr.push_back(nums[idx]);
    helperFunc(idx + 1, arr, nums, ans);
    arr.pop_back();

    auto it = upper_bound(nums.begin() + idx + 1, nums.end(), nums[idx]);

    int next_idx = it - nums.begin();

    if (it != nums.end()) {
      helperFunc(next_idx, arr, nums, ans);
    } else {
      helperFunc(n, arr, nums, ans);
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> arr;

    sort(nums.begin(), nums.end());

    helperFunc(0, arr, nums, ans);

    return ans;
  }
};

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

    for (int i = idx + 1; i < n; i++) {
      if (nums[i] != nums[idx]) {
        helperFunc(i, arr, nums, ans);
        return;
      }
    }

    helperFunc(n, arr, nums, ans);
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

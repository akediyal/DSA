class Solution {
private:
  void helperFunc(int idx, int n, vector<int> &nums, vector<int> &arr,
                  vector<vector<int>> &ans) {
    if (idx == n) {
      ans.push_back(arr);
      return;
    }

    helperFunc(idx + 1, n, nums, arr, ans);

    arr.push_back(nums[idx]);

    helperFunc(idx + 1, n, nums, arr, ans);

    arr.pop_back();
  }

public:
  vector<vector<int>> powerSet(vector<int> &nums) {
    vector<vector<int>> ans;

    vector<int> arr;

    helperFunc(0, nums.size(), nums, arr, ans);

    return ans;
  }
};

class Solution {
private:
  void helperFunc(int idx, vector<int> &arr, vector<vector<int>> &ans,
                  vector<int> &nums, int n) {
    if (idx == n) {
      ans.push_back(arr);
      return;
    }

    arr.push_back(nums[idx]);

    helperFunc(idx + 1, arr, ans, nums, n);

    arr.pop_back();

    helperFunc(idx + 1, arr, ans, nums, n);
  }

public:
  vector<vector<int>> powerSet(vector<int> &nums) {
    vector<vector<int>> ans;

    vector<int> arr;

    helperFunc(0, arr, ans, nums, nums.size());

    return ans;
  }
};

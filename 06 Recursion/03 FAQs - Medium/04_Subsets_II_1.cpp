class Solution {
private:
  void helperFunc(int idx, vector<int> &arr, set<vector<int>> &ans,
                  vector<int> &nums) {
    int n = nums.size();

    if (idx == n) {
      auto t = arr;
      sort(t.begin(), t.end());
      ans.insert(t);
      return;
    }

    arr.push_back(nums[idx]);
    helperFunc(idx + 1, arr, ans, nums);
    arr.pop_back();

    helperFunc(idx + 1, arr, ans, nums);
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    set<vector<int>> temp;
    vector<int> arr;

    helperFunc(0, arr, temp, nums);

    vector<vector<int>> ans(temp.begin(), temp.end());

    return ans;
  }
};

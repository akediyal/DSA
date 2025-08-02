class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    vector<vector<int>> ans;
    ans = getAllPermutations(nums);

    int index = -1;

    for (int i = 0; i < ans.size(); i++) {
      if (nums == ans[i]) {
        index = i;
        break;
      }
    }

    if (index == ans.size() - 1) {
      nums = ans[0];
    } else {
      nums = ans[index + 1];
    }

    return;
  }

private:
  vector<vector<int>> getAllPermutations(vector<int> &nums) {
    vector<vector<int>> ans;

    helperFunc(0, nums, ans);

    sort(ans.begin(), ans.end());

    return ans;
  }

  void helperFunc(int ind, vector<int> &nums, vector<vector<int>> &ans) {

    if (ind == nums.size()) {
      ans.push_back(nums);
    }

    for (int i = ind; i < nums.size(); i++) {
      swap(nums[ind], nums[i]);

      helperFunc(ind + 1, nums, ans);

      swap(nums[ind], nums[i]);
    }
  }
};

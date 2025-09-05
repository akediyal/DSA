class Solution {
private:
  void helperFunc(int idx, int sum, vector<int> &ans, vector<int> &nums) {
    int n = nums.size();

    if (idx == n) {
      ans.push_back(sum);
      return;
    }

    helperFunc(idx + 1, sum + nums[idx], ans, nums);
    helperFunc(idx + 1, sum, ans, nums);
  }

public:
  vector<int> subsetSums(vector<int> &nums) {
    vector<int> ans;

    helperFunc(0, 0, ans, nums);

    return ans;
  }
};

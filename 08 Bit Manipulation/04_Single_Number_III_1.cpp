class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int n = nums.size();

    if (n == 2) {
      if (nums[0] < nums[1]) {
        return {nums[0], nums[1]};
      } else {
        return {nums[1], nums[0]};
      }
    }

    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
      mp[nums[i]]++;
    }

    for (auto it : mp) {
      if (it.second == 1) {
        ans.push_back(it.first);
      }
    }

    sort(ans.begin(), ans.end());

    return ans;
  }
};

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();

    set<vector<int>> triplet_set;

    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(nums[j]);
            temp.push_back(nums[k]);
            sort(temp.begin(), temp.end());
            triplet_set.insert(temp);
          }
        }
      }
    }

    vector<vector<int>> ans(triplet_set.begin(), triplet_set.end());

    return ans;
  }
};

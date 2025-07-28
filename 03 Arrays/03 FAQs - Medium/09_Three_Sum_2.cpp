class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();

    set<vector<int>> triplet_set;

    for (int i = 0; i < n - 2; i++) {
      set<int> hash_set;

      for (int j = i + 1; j < n; j++) {
        int third_element = -(nums[i] + nums[j]);

        if (hash_set.find(third_element) != hash_set.end()) {
          vector<int> temp = {nums[i], nums[j], third_element};
          sort(temp.begin(), temp.end());
          triplet_set.insert(temp);
        }

        hash_set.insert(nums[j]);
      }
    }

    vector<vector<int>> ans(triplet_set.begin(), triplet_set.end());

    return ans;
  }
};

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();

    set<vector<int>> st;

    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        set<long long> hash_set;

        for (int k = j + 1; k < n; k++) {
          long long sum = nums[i] + nums[j];
          sum += nums[k];
          long long fourth_el = target - sum;

          if (hash_set.find(fourth_el) != hash_set.end()) {
            vector<int> temp = {nums[i], nums[j], nums[k],
                                static_cast<int>(fourth_el)};
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }

          hash_set.insert(nums[k]);
        }
      }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
  }
};

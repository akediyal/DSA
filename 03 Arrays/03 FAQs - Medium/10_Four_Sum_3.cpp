class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size();

    set<vector<int>> st;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        int left = j + 1;
        int right = n - 1;

        while (left < right) {
          long long sum = nums[i] + nums[j];
          sum += nums[left];
          sum += nums[right];

          if (sum < target) {
            left++;
          } else if (sum > target) {
            right--;
          } else {
            vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
            st.insert(temp);
            left++, right--;
          }
        }
      }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
  }
};

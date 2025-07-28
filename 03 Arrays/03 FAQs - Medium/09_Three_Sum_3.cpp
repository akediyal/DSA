class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i - 1] == nums[i]) {
        continue;
      }

      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];

        if (sum < 0) {
          j++;
        } else if (sum > 0) {
          k--;
        } else {
          vector<int> temp = {nums[i], nums[j], nums[k]};
          ans.push_back(temp);

          j++, k--;

          while (j < k && nums[j - 1] == nums[j]) {
            j++;
          }

          while (k > j && nums[k - 1] == nums[k]) {
            k--;
          }
        }
      }
    }

    return ans;
  }
};

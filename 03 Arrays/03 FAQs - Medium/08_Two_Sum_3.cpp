class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();

    vector<int> ans;

    vector<vector<int>> element_index;

    for (int i = 0; i < n; i++) {
      element_index.push_back({nums[i], i});
    }

    sort(element_index.begin(), element_index.end(), comparator);

    int left = 0, right = n - 1;

    while (left < right) {
      int sum = element_index[left][0] + element_index[right][0];

      if (sum == target) {
        ans.push_back(element_index[left][1]);
        ans.push_back(element_index[right][1]);
        return ans;
      } else if (sum < target) {
        left++;
      } else {
        right--;
      }
    }

    return {-1, -1};
  }

  static bool comparator(vector<int> &x, vector<int> &y) { return x[0] < y[0]; }
};

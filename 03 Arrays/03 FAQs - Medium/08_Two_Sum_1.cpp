class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();

    vector<int> ans;

    for (int i = 0; i < n - 1; i++) {
      int temp = target - nums[i];

      bool flag = false;

      if (flag) {
        break;
      }

      for (int j = i + 1; j < n; j++) {

        if (nums[j] == temp) {
          ans.push_back(i);
          ans.push_back(j);
          flag = true;
          break;
        }
      }
    }

    return ans;
  }
};

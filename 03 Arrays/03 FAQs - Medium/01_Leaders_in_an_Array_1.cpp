class Solution {
public:
  vector<int> leaders(vector<int> &nums) {
    int n = nums.size();

    vector<int> leader_arr;

    for (int i = 0; i < n - 1; i++) {
      bool isLeader = true;

      for (int j = i + 1; j < n; j++) {

        if (nums[j] >= nums[i]) {
          isLeader = false;
          break;
        }
      }

      if (isLeader) {
        leader_arr.push_back(nums[i]);
      }
    }

    leader_arr.push_back(nums[n - 1]);
    return leader_arr;
  }
};

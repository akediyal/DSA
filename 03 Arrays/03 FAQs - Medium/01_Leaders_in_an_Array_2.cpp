class Solution {
public:
  vector<int> leaders(vector<int> &nums) {
    int n = nums.size();

    vector<int> leader_arr;

    int current_max = nums[n - 1];
    leader_arr.push_back(current_max);

    for (int i = n - 2; i >= 0; i--) {
      if (current_max < nums[i]) {
        current_max = nums[i];
        leader_arr.push_back(current_max);
      }
    }

    reverse(leader_arr.begin(), leader_arr.end());

    return leader_arr;
  }
};

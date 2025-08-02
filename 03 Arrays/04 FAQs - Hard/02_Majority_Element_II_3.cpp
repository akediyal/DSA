class Solution {
public:
  vector<int> majorityElementTwo(vector<int> &nums) {
    int n = nums.size();

    map<int, int> freq;

    int min_needed = int(n / 3) + 1;

    vector<int> ans;

    for (int i = 0; i < n; i++) {
      freq[nums[i]]++;

      if (freq[nums[i]] == min_needed) {
        ans.push_back(nums[i]);
      }

      if (ans.size() == 2) {
        break;
      }
    }

    return ans;
  }
};

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();

    int freq[n + 1] = {0};

    for (auto num : nums) {
      freq[num]++;
    }

    int ans = 0;

    for (int i = 0; i <= n; i++) {
      if (freq[i] != 1) {
        ans = i;
        return ans;
      }
    }

    return ans;
  }
};

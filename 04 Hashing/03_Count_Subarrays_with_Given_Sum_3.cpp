class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> mp;
    mp[0] = 1;

    int prefix_sum = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
      prefix_sum += nums[i];
      int remove = prefix_sum - k;
      cnt += mp[remove];
      mp[prefix_sum]++;
    }

    return cnt;
  }
};

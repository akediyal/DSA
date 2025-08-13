class Solution {
public:
  int subarraysWithXorK(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> mp;
    mp[0] = 1;

    int prefix_xorr = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
      prefix_xorr ^= nums[i];
      int x = prefix_xorr ^ k;
      cnt += mp[x];
      mp[prefix_xorr]++;
    }

    return cnt;
  }
};

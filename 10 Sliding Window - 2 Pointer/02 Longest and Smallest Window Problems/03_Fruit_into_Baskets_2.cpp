class Solution {
public:
  int totalFruits(vector<int> &fruits) {
    int n = fruits.size();
    unordered_map<int, int> mp;
    int max_len = 0;
    int l = 0, r = 0;

    while (r < n) {
      mp[fruits[r]]++;

      if (mp.size() > 2) {
        while (mp.size() > 2) {
          mp[fruits[l]]--;

          if (mp[fruits[l]] == 0) {
            mp.erase(fruits[l]);
          }

          l++;
        }
      }

      if (mp.size() <= 2) {
        int len = r - l + 1;
        max_len = max(max_len, len);
      }

      r++;
    }

    return max_len;
  }
};

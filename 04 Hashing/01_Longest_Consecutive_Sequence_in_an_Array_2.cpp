class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int longest = 1, cnt = 0;
    int last_smaller = INT_MIN;

    for (int i = 0; i < n; i++) {

      if (nums[i] - 1 == last_smaller) {
        last_smaller = nums[i];
        cnt++;
      } else if (nums[i] != last_smaller) {
        last_smaller = nums[i];
        cnt = 1;
      }

      longest = max(longest, cnt);
    }

    return longest;
  }
};

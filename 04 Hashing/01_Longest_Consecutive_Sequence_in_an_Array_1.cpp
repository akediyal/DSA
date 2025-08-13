class Solution {
private:
  bool linearSearch(vector<int> &nums, int num) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == num) {
        return true;
      }
    }

    return false;
  }

public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();

    if (n == 0) {
      return 0;
    }

    int longest = 0;

    for (int i = 0; i < n; i++) {
      int num = nums[i];
      int cnt = 0;

      while (linearSearch(nums, num + 1)) {
        num++, cnt++;
      }

      longest = max(longest, cnt + 1);
    }

    return longest;
  }
};

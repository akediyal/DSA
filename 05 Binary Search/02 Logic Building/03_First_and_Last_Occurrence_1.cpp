class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();

    int first_occ = -1, last_occ = -1;

    for (int i = 0; i < n; i++) {
      if (nums[i] == target) {
        if (first_occ == -1) {
          first_occ = i;
        }
        last_occ = i;
      }
    }

    return {first_occ, last_occ};
  }
};

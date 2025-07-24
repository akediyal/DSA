class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();

    set<int> unique_set;

    for (int i = 0; i < n; i++) {
      unique.insert(nums[i]);
    }

    int unique_elements = unique_set.size();

    int j = 0;
    for (auto element : unique_set) {
      nums[j] = element;
      j++;
    }

    return k;
  }
};

class Solution {
public:
  vector<int> unionArray(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    set<int> unique_nums;
    vector<int> union_set;

    for (int i = 0; i < n; i++) {
      unique_nums.insert(nums1[i]);
    }

    for (int i = 0; i < m; i++) {
      unique_nums.insert(nums2[i]);
    }

    for (auto num : unique_nums) {
      union_set.push_back(num);
    }

    return union_set;
  }
};

class Solution {
public:
  vector<int> unionArray(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<int> union_set;

    int i = 0, j = 0;

    while (i < n && j < m) {
      if (nums1[i] <= nums2[j]) {
        if (union_set.size() == 0 || union_set.back() != nums1[i]) {
          union_set.push_back(nums1[i]);
        }
        i++;
      } else {
        if (union_set.size() == 0 || union_set.back() != nums2[j]) {
          union_set.push_back(nums2[j]);
        }
        j++;
      }
    }

    while (i < n) {
      if (union_set.back() != nums1[i]) {
        union_set.push_back(nums1[i]);
      }
      i++;
    }

    while (j < m) {
      if (union_set.back() != nums2[j]) {
        union_set.push_back(nums2[j]);
      }
      j++;
    }

    return union_set;
  }
};

class Solution {
public:
  vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<int> intersection_arr;

    int i = 0, j = 0;

    while (i < n && j < m) {

      if (nums1[i] < nums2[j]) {
        i++;
      } else if (nums2[j] < nums1[i]) {
        j++;
      } else if (nums1[i] == nums2[j]) {
        intersection_arr.push_back(nums1[i]);
        i++, j++;
      }
    }

    return intersection_arr;
  }
};

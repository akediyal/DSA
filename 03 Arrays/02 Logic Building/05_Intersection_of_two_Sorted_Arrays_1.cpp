class Solution {
public:
  vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<int> intersection_arr;
    vector<int> visited(m, 0);

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < m; j++) {

        if (nums1[i] == nums2[j] && visited[j] == 0) {
          intersection_arr.push_back(nums2[j]);
          visited[j] = 1;
          break;
        } else if (nums2[j] > nums1[i]) {
          break;
        }
      }
    }

    return intersection_arr;
  }
};

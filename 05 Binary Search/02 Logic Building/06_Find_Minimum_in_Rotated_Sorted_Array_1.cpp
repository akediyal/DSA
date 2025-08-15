class Solution {
public:
  int findMin(vector<int> &arr) {
    int n = arr.size();

    int min_el = INT_MAX;

    for (int i = 0; i < n; i++) {
      min_el = min(min_el, arr[i]);
    }

    return min_el;
  }
};

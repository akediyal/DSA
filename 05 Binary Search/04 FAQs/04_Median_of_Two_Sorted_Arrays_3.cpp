class Solution {
public:
  double median(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    if (n1 > n2) {
      return median(arr2, arr1);
    }

    int n = n1 + n2;

    int left = (n + 1) / 2;

    int low = 0, high = n1;

    while (low <= high) {
      int mid1 = low + (high - low) / 2;

      int mid2 = left - mid1;

      int l1 = INT_MIN, l2 = INT_MIN;
      int r1 = INT_MAX, r2 = INT_MAX;

      if (mid1 < n1) {
        r1 = arr1[mid1];
      }

      if (mid2 < n2) {
        r2 = arr2[mid2];
      }

      if (mid1 > 0) {
        l1 = arr1[mid1 - 1];
      }

      if (mid2 > 0) {
        l2 = arr2[mid2 - 1];
      }

      double median = -1;

      if (l1 <= r2 && l2 <= r1) {
        if (n % 2 == 1) {
          median = max(l1, l2);
          return median;
        } else {
          median = (max(l1, l2) + min(r1, r2)) / 2.0;
          return median;
        }
      }

      else if (l1 > r2) {
        high = mid1 - 1;
      }

      else {
        low = mid1 + 1;
      }
    }

    return 0;
  }
};

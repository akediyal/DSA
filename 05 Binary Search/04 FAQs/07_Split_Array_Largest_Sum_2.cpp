class Solution {
private:
  int countSubarrays(vector<int> &a, int max_sum) {
    int n = a.size();

    int subarrays = 1;
    long long subarray_sum = 0;

    for (int i = 0; i < n; i++) {
      if (subarray_sum + a[i] <= max_sum) {
        subarray_sum += a[i];
      } else {
        subarrays++;
        subarray_sum = a[i];
      }
    }

    return subarrays;
  }

public:
  int largestSubarraySumMinimized(vector<int> &a, int k) {
    int n = a.size();

    if (k > n) {
      return -1;
    }

    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int subarrays = countSubarrays(a, mid);

      if (subarrays > k) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};

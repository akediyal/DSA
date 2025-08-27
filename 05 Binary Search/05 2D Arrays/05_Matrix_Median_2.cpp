class Solution {
private:
  int upperBound(vector<int> &arr, int x) {
    int n = arr.size();

    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] > x) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

  int countSmallEquals(vector<vector<int>> &matrix, int x) {
    int rows = matrix.size();

    int cnt = 0;

    for (int i = 0; i < rows; i++) {
      cnt += upperBound(matrix[i], x);
    }

    return cnt;
  }

public:
  int findMedian(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < rows; i++) {
      low = min(low, matrix[i][0]);
      high = max(high, matrix[i][cols - 1]);
    }

    int req = (rows * cols) / 2;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int smallEquals = countSmallEquals(matrix, mid);

      if (smallEquals <= req) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};

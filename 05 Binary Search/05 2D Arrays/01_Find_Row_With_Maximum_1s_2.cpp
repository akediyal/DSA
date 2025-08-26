class Solution {
private:
  int lowerBound(vector<int> arr, int n, int num) {
    int low = 0, high = n - 1;

    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] >= num) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

public:
  int rowWithMax1s(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int cnt_max = 0;
    int idx = -1;

    for (int i = 0; i < rows; i++) {
      int cnt = cols - lowerBound(mat[i], cols, 1);

      if (cnt > cnt_max) {
        cnt_max = cnt;
        idx = i;
      }
    }

    return idx;
  }
};

class Solution {
private:
  int findMaxElement(vector<vector<int>> &arr, int col) {
    int rows = arr.size();

    int max_el = INT_MIN, idx = -1;

    for (int i = 0; i < rows; i++) {
      if (max_el < arr[i][col]) {
        max_el = arr[i][col];
        idx = i;
      }
    }

    return idx;
  }

public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int low = 0, high = cols - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int max_el_idx = findMaxElement(mat, mid);

      int left = mid - 1 >= 0 ? mat[max_el_idx][mid - 1] : -1;
      int right = mid + 1 < cols ? mat[max_el_idx][mid + 1] : -1;

      if (mat[max_el_idx][mid] > left && mat[max_el_idx][mid] > right) {
        return {max_el_idx, mid};
      }

      else if (mat[max_el_idx][mid] < left) {
        high = mid - 1;
      }

      else {
        low = mid + 1;
      }
    }

    return {-1, -1};
  }
};

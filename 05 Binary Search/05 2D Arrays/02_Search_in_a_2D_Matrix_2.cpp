class Solution {
private:
  bool binarySearch(vector<int> &mat, int target) {
    int low = 0, high = mat.size();

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (mat[mid] > target) {
        high = mid - 1;
      } else if (mat[mid] < target) {
        low = mid + 1;
      } else {
        return true;
      }
    }

    return false;
  }

public:
  bool searchMatrix(vector<vector<int>> &mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; i++) {
      if (mat[i][0] <= target && target <= mat[i][cols - 1]) {
        return binarySearch(mat[i], target);
      }
    }

    return false;
  }
};

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    int low = 0, high = rows * cols - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      int row = mid / cols;
      int col = mid % cols;

      if (mat[row][col] == target) {
        return true;
      } else if (mat[row][col] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return false;
  }
};

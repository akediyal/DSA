class Solution {
private:
  bool binarySearch(vector<int> &arr, int target) {
    int n = arr.size();

    int low = 0, high = n - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] == target) {
        return true;
      } else if (arr[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return false;
  }

public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
      bool isPresent = binarySearch(matrix[i], target);

      if (isPresent) {
        return true;
      }
    }

    return false;
  }
};

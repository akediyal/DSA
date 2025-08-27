class Solution {
private:
  void fillArray(vector<vector<int>> &arr1, vector<vector<int>> &arr2) {
    int rows = arr2.size();
    int cols = arr2[0].size();

    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        arr1[i][j] = arr2[i - 1][j - 1];
      }
    }
  }

public:
  vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<int>> arr(rows + 2, vector<int>(cols + 2, -1));

    fillArray(arr, mat);

    for (int i = 1; i <= rows; i++) {
      for (int j = 1; j <= cols; j++) {
        if (arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i - 1][j] &&
            arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i][j - 1]) {
          return {i - 1, j - 1};
        }
      }
    }

    return {-1, -1};
  }
};

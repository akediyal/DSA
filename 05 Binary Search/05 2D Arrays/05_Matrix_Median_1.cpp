class Solution {
public:
  int findMedian(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> arr;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        arr.push_back(matrix[i][j]);
      }
    }

    sort(arr.begin(), arr.end());

    int middle_idx = arr.size() / 2;

    return arr[middle_idx];
  }
};

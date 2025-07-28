class Solution {
public:
  void rotateMatrix(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> temp(rows, vector<int>(cols, 0));

    for (int j = 0; j < cols; j++) {
      for (int i = rows - 1; i >= 0; i--) {
        temp[j][rows - 1 - i] = matrix[i][j];
      }
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        matrix[i][j] = temp[i][j];
      }
    }
  }
};

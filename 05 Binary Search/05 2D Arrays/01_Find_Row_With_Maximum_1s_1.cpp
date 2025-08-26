class Solution {
public:
  int rowWithMax1s(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int cnt_max = 0;
    int idx = -1;

    for (int i = 0; i < rows; i++) {

      int cnt = 0;
      for (int j = 0; j < cols; j++) {
        cnt += mat[i][j];
      }

      if (cnt > cnt_max) {
        cnt_max = cnt;
        idx = i;
      }
    }

    return idx;
  }
};

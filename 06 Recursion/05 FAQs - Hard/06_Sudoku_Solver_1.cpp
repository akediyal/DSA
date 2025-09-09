class Solution {
private:
  bool areRulesMet(vector<vector<char>> &board, int row, int col, char digit) {
    int n = 9;

    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for (int i = 0; i < n; i++) {
      if (board[row][i] == digit) {
        return false;
      }

      if (board[i][col] == digit) {
        return false;
      }

      if (board[start_row + i / 3][start_col + i % 3] == digit) {
        return false;
      }
    }

    return true;
  }

  bool helperFunc(vector<vector<char>> &board) {
    int n = 9;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == '.') {
          for (char digit = '1'; digit <= '9'; digit++) {
            if (areRulesMet(board, i, j, digit)) {
              board[i][j] = digit;
              bool val = helperFunc(board);

              if (val) {
                return true;
              }

              board[i][j] = '.';
            }
          }

          return false;
        }
      }
    }

    return true;
  }

public:
  void solveSudoku(vector<vector<char>> &board) { helperFunc(board); }
};

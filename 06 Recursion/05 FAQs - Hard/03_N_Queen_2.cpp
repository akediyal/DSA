class Solution {
private:
  bool placingIsPossible(int r, int c, vector<string> &board) {
    int n = board.size();

    int row = r, col = c;

    while (col >= 0) {
      if (board[row][col] == 'Q') {
        return false;
      }
      col--;
    }

    col = c;

    while (col >= 0 && row < n) {
      if (board[row][col] == 'Q') {
        return false;
      }
      col--, row++;
    }

    row = r, col = c;

    while (col >= 0 && row >= 0) {
      if (board[row][col] == 'Q') {
        return false;
      }
      col--, row--;
    }

    return true;
  }

  void helperFunc(int col, vector<string> &board, vector<vector<string>> &ans) {
    int n = board.size();

    if (col == n) {
      ans.push_back(board);
      return;
    }

    for (int row = 0; row < n; row++) {
      if (placingIsPossible(row, col, board)) {
        board[row][col] = 'Q';
        helperFunc(col + 1, board, ans);
        board[row][col] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    helperFunc(0, board, ans);

    return ans;
  }
};

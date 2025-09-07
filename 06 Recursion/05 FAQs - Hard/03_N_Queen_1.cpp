class Solution {
private:
  bool placingIsPossible(int r, int c, vector<string> &board) {
    int n = board.size();

    int row = r, col = c;

    while (row >= 0) {
      if (board[row][col] == 'Q') {
        return false;
      }
      row--;
    }

    row = r;

    while (row >= 0 && col < n) {
      if (board[row][col] == 'Q') {
        return false;
      }
      row--, col++;
    }

    row = r, col = c;

    while (row >= 0 && col >= 0) {
      if (board[row][col] == 'Q') {
        return false;
      }
      row--, col--;
    }

    return true;
  }

  void helperFunc(int row, vector<string> &board, vector<vector<string>> &ans) {
    int n = board.size();

    if (row == n) {
      ans.push_back(board);
      return;
    }

    for (int col = 0; col < n; col++) {
      if (placingIsPossible(row, col, board)) {
        board[row][col] = 'Q';
        helperFunc(row + 1, board, ans);
        board[row][col] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board;

    string s = "";

    for (int i = 0; i < n; i++) {
      s += '.';
    }

    for (int i = 0; i < n; i++) {
      board.push_back(s);
    }

    helperFunc(0, board, ans);

    return ans;
  }
};

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    unsigned m = board.size();
    unsigned n = board[0].size();
    if (m <= 2 || n <= 2)
      return;
    
    static const function<void(int,int)> markBorder = [&](int i, int j) {
      if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O') {
        board[i][j] = 'B';
        markBorder(i + 1, j);
        markBorder(i - 1, j);
        markBorder(i, j + 1);
        markBorder(i, j - 1);
      }
    };
    
    for (unsigned i = 0; i < m; ++i) {
      markBorder(i, 0);
      markBorder(i, n - 1);
    }
    
    for (unsigned j = 0; j < n; ++j) {
      markBorder(0, j);
      markBorder(m - 1, j);
    }

    for (unsigned i = 0; i < m; ++i) {
      for (unsigned j = 0; j < n; ++j) {
        char c = board[i][j];
        if (c != 'X')
          board[i][j] = c == 'O' ? 'X' : 'O';
      }
    }
  }
};
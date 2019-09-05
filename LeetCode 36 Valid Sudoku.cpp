// LeetCode 36 Valid Sudoku.cpp

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false)), col(row), grid(row);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                if (row[i][ch - '1'] ||
                    col[j][ch - '1'] ||
                    grid[i / 3 + j / 3 * 3][ch - '1']) {
                    return false;
                }
                row[i][ch - '1'] = true;
                col[j][ch - '1'] = true;
                grid[i / 3 + j / 3 * 3][ch - '1'] = true;
            }
        }
        return true;
    }
};
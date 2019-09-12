// LeetCode 529 Minesweeper.cpp

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        dfs(board, click[0], click[1]);
        return board;
    }
    
private:
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        
        board[x][y] = '0';
        for (vector<int> &d : dirs) {
            if (0 <= x + d[0] && x + d[0] < board.size()    &&
                0 <= y + d[1] && y + d[1] < board[0].size() &&
                board[x + d[0]][y + d[1]] == 'M') {
                board[x][y]++;
            }
        }
        if (board[x][y] > '0') {
            return;
        }
        
        board[x][y] = 'B';
        for (vector<int> &d : dirs) {
            if (0 <= x + d[0] && x + d[0] < board.size()    &&
                0 <= y + d[1] && y + d[1] < board[0].size() &&
                board[x + d[0]][y + d[1]] == 'E') {
                dfs(board, x + d[0], y + d[1]);
            }
        }
    }
    
private:
    vector<vector<int>> dirs = {
        {-1, -1}, {-1,  0}, {-1,  1}, { 0, -1},
        { 0,  1}, { 1, -1}, { 1,  0}, { 1,  1}
    };
};
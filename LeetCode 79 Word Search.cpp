// LeetCode 79 Word Search.cpp

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool backtrack(vector<vector<char>> &board, int x, int y, string &word, int wi) {
        if (wi >= word.size()) return true;
        if (x < 0 || x >= board.size()) return false;
        if (y < 0 || y >= board[0].size()) return false;
        if (board[x][y] != word[wi]) return false;
        
        char ch = board[x][y];
        board[x][y] = '*';
        
        bool ans = backtrack(board, x - 1, y, word, wi + 1) ||
            backtrack(board, x + 1, y, word, wi + 1) ||
            backtrack(board, x, y - 1, word, wi + 1) ||
            backtrack(board, x, y + 1, word, wi + 1);
        
        board[x][y] = ch;
        return ans;
    }
};
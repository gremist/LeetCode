// LeetCode 999 Available Captures for Rook.cpp

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {        
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    int ans = 0;
                    for (int k = i; k  < 8 && board[k][j] != 'B'; k++) {
                        if (board[k][j] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    for (int k = j; k >= 0 && board[i][k] != 'B'; k--) {
                        if (board[i][k] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    for (int k = i; k >= 0 && board[k][j] != 'B'; k--) {
                        if (board[k][j] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    for (int k = j; k  < 8 && board[i][k] != 'B'; k++) {
                        if (board[i][k] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    return ans;
                }
            }
        }
        return 0;
    }
};
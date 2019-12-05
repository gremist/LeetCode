// LeetCode 1275 Find Winner on a Tic Tac Toe Game.cpp

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int board = 0, ms = moves.size();
        if (ms < 5) return "Pending";
        for (int i = ms - 1; i >= 0; i -= 2) {
            board |= 1 << 3 * moves[i][0] + moves[i][1];
        }
        for (int e : ends) {
            if ((board & e) == e) {
                return ms % 2 ? "A" : "B";
            }
        }
        return ms < 9 ? "Pending" : "Draw";
    }

private:
    vector<int> ends = {7, 56, 73, 84, 146, 273, 292, 448};
};
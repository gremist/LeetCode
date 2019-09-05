// LeetCode 657 Robot Return to Origin.cpp

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char move : moves) {
            switch (move) {
            case 'U':
                y++;
                break;
            case 'R':
                x++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
            }
        }
        return x == 0 && y == 0;
    }
};
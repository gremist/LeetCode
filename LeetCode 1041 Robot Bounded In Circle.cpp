// LeetCode 1041 Robot Bounded In Circle.cpp

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, di = 0;
        for (char instr : instructions) {
            switch (instr) {
            case 'G':
                x += dirs[di][0];
                y += dirs[di][1];
                break;
            case 'L':
                di = (di + 3) % 4;
                break;
            case 'R':
                di = (di + 1) % 4;
            }
        }
        return !x && !y || di;
    }
    
private:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
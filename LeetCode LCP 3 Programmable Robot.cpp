// LeetCode LCP 3 Programmable Robot.cpp

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        unordered_set<long> s;
        int m = 0, n = 0;
        for (char ch : command) {
            s.insert(1l * m << 32 | n);
            if (ch == 'R') {
                m++;
            } else {
                n++;
            }
        }
        
        int r = min(x / m, y / n);
        if (s.find(1l * (x - r * m) << 32 | y - r * n) == s.end()) {
            return false;
        }
        
        for (vector<int> &ob : obstacles) {
            if (ob[0] <= x && ob[1] <= y) {
                r = min(ob[0] / m, ob[1] / n);
                if (s.find(1l * (ob[0] - r * m) << 32 | ob[1] - r * n) != s.end()) {
                    return false;
                }
            }
        }
        return true;
    }
};
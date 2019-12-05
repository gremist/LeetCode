// LeetCode 991 Broken Calculator.cpp

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (X < Y) {
            Y = Y % 2 ? Y + 1 : Y / 2;
            ans++;
        }
        return ans + X - Y;
    }
};
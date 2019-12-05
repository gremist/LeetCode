// LeetCode 885 Spiral Matrix III.cpp

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans(R * C, vector<int>(2));
        int ai = 0, di = 0, end = 2;
        while (ai < R * C) {
            for (int i = 0; i < end / 2; i++) {
                if (0 <= r0 && r0 < R && 0 <= c0 && c0 < C) {
                    ans[ai][0]   = r0;
                    ans[ai++][1] = c0;
                }
                r0 += dirs[di][0];
                c0 += dirs[di][1];
            }
            end++;
            di = (di + 1) % 4;
        }
        return ans;
    }
    
private:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
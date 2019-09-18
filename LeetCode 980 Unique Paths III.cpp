// LeetCode 980 Unique Paths III.cpp

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y, step = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    step++;
                } else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        return backtrack(grid, x, y, step);
    }
    
private:
    int backtrack(vector<vector<int>>& grid, int x, int y, int step) {
        if (x < 0 || x >= grid.size()) return 0;
        if (y < 0 || y >= grid[0].size()) return 0;
        if (grid[x][y] == -1) return 0;
        if (step <= 0 && grid[x][y] == 2) return 1;
        if (step <= 0 || grid[x][y] == 2) return 0;
        grid[x][y] = -1;
        int ans = backtrack(grid, x - 1, y, step - 1) +
            backtrack(grid, x + 1, y, step - 1) +
            backtrack(grid, x, y - 1, step - 1) +
            backtrack(grid, x, y + 1, step - 1);
        grid[x][y] = 0;
        return ans;
    }
};
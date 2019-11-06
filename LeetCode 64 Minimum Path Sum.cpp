// LeetCode 64 Minimum Path Sum.cpp

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i > 0 && j > 0) {
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
                } else if (i > 0) {
                    grid[i][j] += grid[i - 1][j];
                } else if (j > 0) {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }
        return grid.back().back();
    }
};
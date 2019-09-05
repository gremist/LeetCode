// LeetCode 695 Max Area of Island.cpp

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    max_area = max(dfs(grid, i, j), max_area);
                }
            }
        }
        return max_area;
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size()) return 0;
        if (y < 0 || y >= grid[0].size()) return 0;
        if (grid[x][y] !=  1) return 0;
        
        grid[x][y] = -1;    // 搜索过的区域标记为-1
        
        int area = 0;
        area += dfs(grid, x - 1, y);
        area += dfs(grid, x + 1, y);
        area += dfs(grid, x, y - 1);
        area += dfs(grid, x, y + 1);
        return area + 1;
    }
};
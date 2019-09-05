// LeetCode 200 Number of Islands.cpp

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }

private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size())    return;
        if (y < 0 || y >= grid[0].size()) return;
        if (grid[x][y] !=  '1') return;
        
        grid[x][y] = '0';
        
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
};
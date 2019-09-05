// LeetCode 463 Island Perimeter.cpp

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    if (i - 1 < 0 || grid[i - 1][j] == 0) {
                        perimeter += 2;
                    }
                    if (j - 1 < 0 || grid[i][j - 1] == 0) {
                        perimeter += 2;
                    }
                }
            }
        }
        return perimeter;
    }
};
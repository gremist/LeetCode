// LeetCode 994 Rotting Oranges.cpp

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int fresh = 0;
        queue<int> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push(i * n + j);
                }
            }
        }

        int depth = 0;
        while (!q.empty()) {
            for (int qi = 0, qs = q.size(); qi < qs; qi++) {
                int i = q.front() / n;
                int j = q.front() % n;
                q.pop();
                for (vector<int> &d : dirs) {
                    if (0 <= i + d[0] && i + d[0] < m &&
                        0 <= j + d[1] && j + d[1] < n &&
                        grid[i + d[0]][j + d[1]] == 1) {
                        grid[i + d[0]][j + d[1]] = 2;
                        fresh--;
                        q.push((i + d[0]) * n + j + d[1]);
                    }
                }
            }
            depth++;
        }
        return fresh ? -1 : max(0, depth - 1);
    }
    
private:
    vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
};
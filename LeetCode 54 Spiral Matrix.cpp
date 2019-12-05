// LeetCode 54 Spiral Matrix.cpp

// 方法1：逐层迭代
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans(m * n);
        for (int r = 0, ai = 0; ai < m * n; r++) {
            for (int j = r; j < n - r; j++) {       // →
                ans[ai++] = matrix[r][j];
            }
            for (int i = r + 1; i < m - r; i++) {   // ↓
                ans[ai++] = matrix[i][n - r - 1];
            }
            if (ai >= m * n) {
                return ans;
            }
            for (int j = n - r - 2; j >= r; j--) {  // ←
                ans[ai++] = matrix[m - r - 1][j];
            }
            for (int i = m - r - 2; i > r; i--) {   // ↑
                ans[ai++] = matrix[i][r];
            }
        }
        return ans;
    }
};

// 方法2：逐边迭代
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans(m * n);
        vector<int> ends = {n, m - 1};
        int x = 0, y = -1, ai = 0, di = 0;
        while (ai < m * n) {
            for (int i = 0; i < ends[di % 2]; i++) {
                x += dirs[di][0];
                y += dirs[di][1];
                ans[ai++] = matrix[x][y];
            }
            ends[di % 2]--;
            di = (di + 1) % 4;
        }
        return ans;
    }
    
private:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
// LeetCode 54 Spiral Matrix.cpp

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans;
        for (int r = 0; r < min(m, n) / 2; r++) {
            for (int j = r; j < n - r - 1; j++) {   // →
                ans.push_back(matrix[r][j]);
            }
            for (int i = r; i < m - r - 1; i++) {   // ↓
                ans.push_back(matrix[i][n - r - 1]);
            }
            for (int j = n - r - 1; j > r; j--) {   // ←
                ans.push_back(matrix[m - r - 1][j]);
            }
            for (int i = m - r - 1; i > r; i--) {   // ↑
                ans.push_back(matrix[i][r]);
            }
        }
        if (m <= n && m % 2 == 1) {
            for (int j = m / 2; j < n - m / 2; j++) {
                ans.push_back(matrix[m / 2][j]);
            }
        }
        if (m  > n && n % 2 == 1) {
            for (int i = n / 2; i < m - n / 2; i++) {
                ans.push_back(matrix[i][n / 2]);
            }
        }
        return ans;
    }
};
// LeetCode 59 Spiral Matrix II.cpp

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        for (int r = 0, count = 1; count <= n * n; r++) {
            for (int j = r; j < n - r; j++) {       // →
                ans[r][j] = count++;
            }
            for (int i = r + 1; i < n - r; i++) {   // ↓
                ans[i][n - r - 1] = count++;
            }
            if (count > n * n) {
                return ans;
            }
            for (int j = n - r - 2; j >= r; j--) {  // ←
                ans[n - r - 1][j] = count++;
            }
            for (int i = n - r - 2; i > r; i--) {   // ↑
                ans[i][r] = count++;
            }
        }
        return ans;
    }
};
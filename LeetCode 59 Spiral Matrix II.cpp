// LeetCode 59 Spiral Matrix II.cpp

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int r = 0, count = 1; r < (n + 1) / 2; r++) {
            for (int j = r; j < n - r - 1; j++) {   // →
                ans[r][j] = count++;
            }
            for (int i = r; i < n - r - 1; i++) {   // ↓
                ans[i][n - r - 1] = count++;
            }
            for (int j = n - r - 1; j > r; j--) {   // ←
                ans[n - r - 1][j] = count++;
            }
            for (int i = n - r - 1; i > r; i--) {   // ↑
                ans[i][r] = count++;
            }
        }
        if (n % 2 == 1) {
            ans[n / 2][n / 2] = n * n;
        }
        return ans;
    }
};
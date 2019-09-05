// LeetCode 661 Image Smoother.cpp

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> ans = M;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 1;
                if (i > 0) {
                    ans[i][j] += M[i - 1][j];
                    cnt++;
                }
                if (i < m - 1) {
                    ans[i][j] += M[i + 1][j];
                    cnt++;
                }
                if (j > 0) {
                    ans[i][j] += M[i][j - 1];
                    cnt++;
                }
                if (j < n - 1) {
                    ans[i][j] += M[i][j + 1];
                    cnt++;
                }
                if (i > 0 && j > 0) {
                    ans[i][j] += M[i - 1][j - 1];
                    cnt++;
                }
                if (i > 0 && j < n - 1) {
                    ans[i][j] += M[i - 1][j + 1];
                    cnt++;
                }
                if (i < m - 1 && j > 0) {
                    ans[i][j] += M[i + 1][j - 1];
                    cnt++;
                }
                if (i < m - 1 && j < n - 1) {
                    ans[i][j] += M[i + 1][j + 1];
                    cnt++;
                }
                ans[i][j] /= cnt;
            }
        }
        return ans;
    }
};
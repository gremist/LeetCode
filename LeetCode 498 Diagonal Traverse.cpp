// LeetCode 498 Diagonal Traverse.cpp

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans(m * n);
        int i = 0, j = 0;
        for (int &num : ans) {
            num = matrix[i][j];
            if ((i + j) % 2) {
                if (i >= m - 1) { j++; continue; }
                if (j <= 0)     { i++; continue; }
                i++; j--;
            } else {
                if (j >= n - 1) { i++; continue; }
                if (i <= 0)     { j++; continue; }
                i--; j++;
            }
        }
        return ans;
    }
};
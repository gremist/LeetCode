// LeetCode 867 Transpose Matrix.cpp

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ans(A[0].size(), vector<int>(A.size()));
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) {
                ans[i][j] = A[j][i];
            }
        }
        return ans;
    }
};
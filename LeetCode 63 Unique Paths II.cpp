// LeetCode 63 Unique Paths II.cpp

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<long> dp(obstacleGrid[0].size());
        dp[0] = 1;
        for (vector<int> &og : obstacleGrid) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                if (og[j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};
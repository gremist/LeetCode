// LeetCode 70 Climbing Stairs.cpp

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp = {1, 2, 0};
        for (int i = 2; i < n; i++) {
            dp[i % 3] = dp[(i + 1) % 3] + dp[(i + 2) % 3];
        }
        return dp[(n + 2) % 3];
    }
};
// LeetCode 746 Min Cost Climbing Stairs.cpp

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(3, 0);
        for (int i = 0; i < size; i++) {
            dp[i % 3] = min(dp[(i + 1) % 3], dp[(i + 2) % 3]) + cost[i];
        }
        return min(dp[(size + 1) % 3], dp[(size + 2) % 3]);
    }
};
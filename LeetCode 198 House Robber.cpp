// LeetCode 198 House Robber.cpp

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(2);
        for (int i = 0; i < nums.size(); i++) {
            dp[i % 2] = max(dp[i % 2] + nums[i], dp[(i + 1) % 2]);
        }
        return dp[(nums.size() + 1) % 2];
    }
};
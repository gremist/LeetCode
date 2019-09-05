// LeetCode 198 House Robber.cpp

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> dp = {nums[0], max(nums[0], nums[1]), 0};
        for (int i = 2; i < nums.size(); i++) {
            dp[i % 3] = max(dp[(i - 2) % 3] + nums[i], dp[(i - 1) % 3]);
        }
        return dp[(nums.size() - 1) % 3];
    }
};
// LeetCode 494 Target Sum.cpp

// 方法1：深度优先搜索
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, S, 0);
    }
    
private:
    int dfs(vector<int> &nums, long S, int ni) {
        if (ni >= nums.size()) return S ? 0 : 1;
        return dfs(nums, S + nums[ni], ni + 1) +
            dfs(nums, S - nums[ni], ni + 1);
    }
};

// 方法2：动态规划
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(S) || (sum + S) % 2) {
            return 0;
        }
        vector<int> dp((sum + S) / 2 + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = dp.size() - 1; i >= n; i--) {
                dp[i] += dp[i - n];
            }
        }
        return dp.back();
    }
};
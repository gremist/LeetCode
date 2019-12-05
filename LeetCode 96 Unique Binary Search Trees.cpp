// LeetCode 96 Unique Binary Search Trees.cpp

// 方法1：动态规划
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

// 方法2：卡特兰数
class Solution {
public:
    int numTrees(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = ans * (4l * i - 2) / (i + 1);
        }
        return ans;
    }
};
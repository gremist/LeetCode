// LeetCode 509 Fibonacci Number.cpp

// 方法1：迭代
class Solution {
public:
    int fib(int N) {
        vector<int> dp = {0, 1};
        for (int i = 2; i <= N; i++) {
            dp[i % 2] = dp[0] + dp[1];
        }
        return dp[N % 2];
    }
};

// 方法2：递归
class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        return fib(N - 2) + fib(N - 1);
    }
};
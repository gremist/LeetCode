// LeetCode 91 Decode Ways.cpp

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp = {0, 1};
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i - 1] != '1' && (s[i - 1] != '2' || s[i] > '6')) {
                dp[i % 2] = 0;
            }
            if (s[i] > '0') {
                dp[i % 2] += dp[(i + 1) % 2];
            }
        }
        return dp[(s.size() + 1) % 2];
    }
};
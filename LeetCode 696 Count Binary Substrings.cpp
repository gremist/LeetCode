// LeetCode 696 Count Binary Substrings.cpp

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, per = 0, cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                cur++;
            } else {
                per = cur;
                cur = 1;
            }
            if (per >= cur) {
                ans++;
            }
        }
        return ans;
    }
};
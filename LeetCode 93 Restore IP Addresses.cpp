// LeetCode 93 Restore IP Addresses.cpp

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        backtrack(ans, "", s, 0, 0);
        return ans;
    }
    
private:
    void backtrack(vector<string> &ans, string cur, string &s, int bi, int si) {
        if (s.size() - si < 4 - bi) return;
        if (s.size() - si > 3 * (4 - bi)) return;
        if (bi >= 4) {
            cur.pop_back();
            ans.push_back(cur);
            return;
        }
        for (int i = si, n = 0; i < si + 3; i++) {
            n = 10 * n + s[i] - '0';
            if (n <= 255) {
                cur += s[i];
                backtrack(ans, cur + ".", s, bi + 1, i + 1);
            }
            if (n == 0) {
                break;
            }
        }
    }
};
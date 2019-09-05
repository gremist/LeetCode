// LeetCode 482 License Key Formatting.cpp

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                if (ans.size() % (K + 1) == K) {
                    ans += "-";
                }
                ans += toupper(S[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
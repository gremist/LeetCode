// LeetCode 859 Buddy Strings.cpp

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        vector<int> ht(26, 0);
        bool sp = false, dp = false;
        for (int i = 0, last = -1; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (last < 0) {
                    last = i;
                } else if (!dp && A[last] == B[i] && A[i] == B[last]) {
                    dp = true;
                } else {
                    return false;
                }
            } else if (!sp && last < 0 && ++ht[A[i] - 'a'] >= 2) {
                sp = true;
            }
        }
        return dp || sp;
    }
};
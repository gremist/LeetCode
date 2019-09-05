// LeetCode 942 DI String Match.cpp

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int ss = S.size(), min = 0, max = ss;
        vector<int> ans(ss + 1);
        for (int i = 0; i < ss; i++) {
            ans[i] = S[i] == 'I' ? min++ : max--;
        }
        ans[ss] = max;
        return ans;
    }
};
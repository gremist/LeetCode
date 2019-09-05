// LeetCode 784 Letter Case Permutation.cpp

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backtrack(ans, S, 0);
        return ans;
    }
    
private:
    void backtrack(vector<string> &ans, string &S, int si) {
        if (si >= S.size()) {
            ans.push_back(S);
            return;
        }
        backtrack(ans, S, si + 1);
        if (isalpha(S[si])) {
            S[si] ^= 0x20;
            backtrack(ans, S, si + 1);
            S[si] ^= 0x20;
        }
    }
};
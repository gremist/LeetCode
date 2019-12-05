// LeetCode 131 Palindrome Partitioning.cpp

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        backtrack(ans, cur, s, 0);
        return ans;
    }
    
private:
    void backtrack(vector<vector<string>> &ans, vector<string> &cur, string &s, int si) {
        if (si >= s.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = si; i < s.size(); i++) {
            if (isPalindrome(s, si, i)) {
                cur.push_back(s.substr(si, i - si + 1));
                backtrack(ans, cur, s, i + 1);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
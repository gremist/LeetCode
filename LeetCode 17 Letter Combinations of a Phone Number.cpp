// LeetCode 17 Letter Combinations of a Phone Number.cpp

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans;
        string cur(digits.size(), '*');
        backtrack(ans, cur, digits, 0);
        return ans;
    }

private:
    void backtrack(vector<string> &ans, string &cur, string &digits, int di) {
        if (di >= digits.size()) {
            ans.push_back(cur);
            return;
        }
        for (char ch : m[digits[di]]) {
            cur[di] = ch;
            backtrack(ans, cur, digits, di + 1);
        }
    }
    
private:
    unordered_map<char, string> m = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
};
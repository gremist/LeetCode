// LeetCode 1021 Remove Outermost Parentheses.cpp

class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int open = 0;
        for (char ch : S) {
            if (ch == ')') {
                open--;
            }
            if (open > 0) {
                ans += ch;
            }
            if (ch == '(') {
                open++;
            }
        }
        return ans;
    }
};
// LeetCode 856 Score of Parentheses.cpp

class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, open = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                open++;
            } else {
                open--;
                if (S[i - 1] == '(') {
                    ans += 1 << open;
                }
            }
        }
        return ans;
    }
};
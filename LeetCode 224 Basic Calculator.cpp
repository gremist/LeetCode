// LeetCode 224 Basic Calculator.cpp

class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int ans = 0, num = 0, sign = 1;
        for (char ch : s) {
            if (isdigit(ch)) {
                num = 10 * num + (ch - '0');
            } else if (ch == '+') {
                ans += sign * num;
                num = 0;
                sign = 1;
            } else if (ch == '-') {
                ans += sign * num;
                num = 0;
                sign = -1;
            } else if (ch == '(') {
                stack.push(ans);
                stack.push(sign);
                ans = 0;
                sign = 1;
            } else if (ch == ')') {
                ans += sign * num;
                ans *= stack.top();
                stack.pop();
                ans += stack.top();
                stack.pop();
                num = 0;
            }
        }
        return ans + sign * num;
    }
};
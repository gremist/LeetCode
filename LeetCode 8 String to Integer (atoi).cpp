// LeetCode 8 String to Integer (atoi).cpp

class Solution {
public:
    int myAtoi(string str) {
        int ans = 0, sign = 0;
        for (char ch : str) {
            if (!sign && ch == ' ') {
                continue;
            } else if (!sign && ch == '-') {
                sign = -1;
            } else if (!sign && ch == '+') {
                sign = 1;
            } else if (!sign && '0' <= ch && ch <= '9') {
                sign = 1;
                ans = ch - '0';
            } else if ('0' <= ch && ch <= '9') {
                if (sign > 0 && (INT_MAX - ch + '0') / 10 < ans) {
                    return INT_MAX;     // 正溢出
                }
                if (sign < 0 && (INT_MIN + ch - '0') / 10 > ans) {
                    return INT_MIN;     // 负溢出
                }
                ans = ans * 10 + sign * (ch - '0');
            } else {
                break;
            }
        }
        return ans;
    }
};
// LeetCode 7 Reverse Integer.cpp

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            if (ans  > INT_MAX / 10 ||
                ans  < INT_MIN / 10 ||
                ans == INT_MAX && x % 10 >  7 ||
                ans == INT_MIN && x % 10 < -8) {
                return 0;
            }
            ans = 10 * ans + x % 10;
            x /= 10;
        }
        return ans;
    }
};
// LeetCode 367 Valid Perfect Square.cpp

class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 1, hi = min(num, 46340);   // sqrt(INT_MAX) = 46340
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid * mid < num) {
                lo = mid + 1;
            } else if (mid * mid > num) {
                hi = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
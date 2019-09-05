// LeetCode 69 Sqrt(x).cpp

class Solution {
public:
    int mySqrt(int x) {
        int lo = 1, hi = min(x, 46340); // sqrt(INT_MAX) = 46340
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid * mid <= x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};
// LeetCode 441 Arranging Coins.cpp

class Solution {
public:
    int arrangeCoins(int n) {
        int lo = 0, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if ((1l + mid) * mid <= 2l * n) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};
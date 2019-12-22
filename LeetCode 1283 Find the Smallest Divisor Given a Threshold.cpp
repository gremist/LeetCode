// LeetCode 1283 Find the Smallest Divisor Given a Threshold.cpp

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1000000;
        while (lo <= hi) {
            int sum = 0, mid = (lo + hi) / 2;
            for (int n : nums) {
                sum += (n - 1) / mid + 1;
            }
            if (sum > threshold) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};